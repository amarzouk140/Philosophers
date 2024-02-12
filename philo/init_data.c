/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:34:54 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/12 17:43:28 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_program *program, t_params *params)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&program->dead_lock, NULL))
		return (ft_print("Error initiate mutex", 2), 1);
	if (pthread_mutex_init(&program->meal_lock, NULL))
		return (ft_print("Error initiate mutex", 2), 1);
	if (pthread_mutex_init(&program->write_lock, NULL))
		return (ft_print("Error initiate mutex", 2), 1);
	while (i < params->philo_count)
	{
		if (pthread_mutex_init(&program->forks[i], NULL))
			return (ft_print("Error initiate mutex", 2), 1);
		i++;
	}
	return (0);
}

void	philo_data(t_program *program, t_params *params)
{
	t_philo	*philos;
	int		i;

	philos = program->philos;
	i = 0;
	while (i < params->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].params = params;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_current();
		philos[i].start_time = get_current();
		philos[i].dead = &program->dead_flag;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].write_lock = &program->write_lock;
		philos[i].l_fork = &program->forks[i];
		if (i == 0)
			philos[i].r_fork = &program->forks[params->philo_count - 1];
		else
			philos[i].r_fork = &program->forks[(i - 1)];
		i++;
	}
}

int	init_philo(t_program *data, int ac, char **av)
{
	data->params.philo_count = ft_atol(av[1]);
	data->params.ttd = ft_atol(av[2]);
	data->params.tte = ft_atol(av[3]);
	data->params.tts = ft_atol(av[4]);
	if (ac == 6)
		data->params.tte_times = ft_atol(av[5]);
	else
		data->params.tte_times = -1;
	data->dead_flag = 0;
	if (init_forks(data, &data->params))
		return (2);
	philo_data(data, &data->params);
	if (init_thread(data->philos, data))
		return (2);
	return (0);
}
