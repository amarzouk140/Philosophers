/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:14:01 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/11 18:45:27 by ayman_marzo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	philos->start_time = get_current();
	while (i < philos->params->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			destroy(data);
		i++;
	}
}

void	join_thread(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (pthread_join(philos[i].thread, NULL))
			destroy(data);
		i++;
	}
}

void	destroy(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->params.philo_count)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
}

void	init_thread(t_philo *philos, t_program *data)
{
	create_thread(philos, data);
	monitor(philos);
	join_thread(philos, data);
	destroy(data);
}
