/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:27 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/07 14:23:13 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	*philo->dead = 1;
	pthread_mutex_unlock((philo->dead_lock));
}

int	check_dead_time(t_philo *philo)
{
	int		i;
	size_t	time;

	i = 0;
	while (i < philo->params->philo_count)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		time = get_current() - philo[i].last_meal;
		if (time > philo[i].params->ttd)
		{
			print_message(&philo[i], "died 💀");
			kill_philos(philo);
		}
		if (dead(philo))
			return (pthread_mutex_unlock(philo[i].meal_lock), 1);
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	return (0);
}

int	finish_eating(t_philo *philo)
{
	int	i;
	int	j;
	int	ate;

	i = 0;
	j = 0;
	while (i < philo->params->philo_count)
	{
		pthread_mutex_lock(philo->meal_lock);
		ate = philo[i].meals_eaten;
		if (ate == philo->params->tte_times && philo[i].eating == 0)
		{
			pthread_mutex_unlock(philo->meal_lock);
			j++;
		}
		else
			pthread_mutex_unlock(philo->meal_lock);
		if (j == philo->params->philo_count)
		{
			kill_philos(philo);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor(t_philo *philos)
{
	while (1)
	{
		usleep(1000);
		if (check_dead_time(philos) || finish_eating(philos))
			break ;
	}
}
