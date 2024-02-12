/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:14:01 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/12 17:40:03 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	philos->start_time = get_current();
	while (i < philos->params->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (destroy(data), 1);
		i++;
	}
	return (0);
}

int	join_thread(t_philo *philos, t_program *data)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (destroy(data), 1);
		i++;
	}
	return (0);
}

int	destroy(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->params.philo_count)
	{
		if (pthread_mutex_destroy(&program->forks[i]))
			return (ft_print("Error destory mutex", 2), 1);
		i++;
	}
	if (pthread_mutex_destroy(&program->dead_lock))
		return (ft_print("Error destory mutex", 2), 1);
	if (pthread_mutex_destroy(&program->meal_lock))
		return (ft_print("Error destory mutex", 2), 1);
	if (pthread_mutex_destroy(&program->write_lock))
		return (ft_print("Error destory mutex", 2), 1);
	return (0);
}

int	init_thread(t_philo *philos, t_program *data)
{
	if (create_thread(philos, data))
		return (ft_print("error creating threads", 2), 1);
	monitor(philos);
	if (join_thread(philos, data))
		return (ft_print("error joining threads", 2), 1);
	if (destroy(data))
		return (1);
	return (0);
}
