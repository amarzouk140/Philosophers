/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:33:16 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/02/15 08:33:01 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_current(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 21);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_current();
	while ((get_current() - start) < ms)
		usleep(500);
	return (0);
}

void	print_action(t_philo *philo, char *action)
{
	sem_wait(philo->write_lock);
	printf("%zu %d %s\n", get_current() - philo->start_time, philo->id, action);
	sem_post(philo->write_lock);
}

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		sem_wait(philo->dead);
		sem_wait(philo->meals_lock);
		if (get_current() - philo->last_meal >= philo->ttd)
		{
			print_action(philo, "died 💀");
			exit(1);
		}
		sem_post(philo->dead);
		sem_post(philo->meals_lock);
		usleep(100);
	}
}
