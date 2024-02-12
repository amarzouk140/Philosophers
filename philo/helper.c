/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:33:26 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/12 17:41:00 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current(void)
{
	struct timeval	time;

	if ((gettimeofday(&time, NULL)) == -1)
		ft_print("gettimeofday() error\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->write_lock);
	if (!dead(philo))
	{
		printf("%lu philosopher %d %s\n", get_current() - philo->start_time,
			philo->id, message);
	}
	pthread_mutex_unlock(philo->write_lock);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current();
	while ((get_current() - start) < milliseconds)
	{
		if (dead(philo))
			return (0);
		usleep(500);
	}
	return (0);
}
