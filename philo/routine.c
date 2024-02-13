/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:40:24 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/13 14:14:17 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	is_eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current();
	philo->meals_eaten++;
	philo->eating = 1;
	pthread_mutex_unlock(philo->meal_lock);
	print_message(philo, "has taken a fork 🍴");
	print_message(philo, "has taken a fork 🍴");
	print_message(philo, "is eating 🍽️");
	ft_usleep(philo->params->tte, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, "has taken a fork 🍴");
	ft_usleep(philo->params->tte, philo);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->philo_count == 1)
		return (one_philo(philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->tte, philo);
	while (!dead(philo))
	{
		is_eating(philo);
		print_message(philo, "is sleeping 🛌😴💤");
		ft_usleep(philo->params->tts, philo);
		print_message(philo, "is thinking 🧠🤫");
		pthread_mutex_lock(philo->meal_lock);
		if (philo->meals_eaten == philo->params->tte_times
			&& philo->eating == 0)
		{
			pthread_mutex_unlock(philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(philo->meal_lock);
		if (philo->params->philo_count % 2)
			ft_usleep(2, philo);
	}
	return (arg);
}
