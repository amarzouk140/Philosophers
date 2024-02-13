/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:45:15 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/13 09:52:28 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_th(t_threads *th, char **av)
{
	th->philos_count = ft_atol(av[1]);
	th->t_die = ft_atol(av[2]);
	th->t_eat = ft_atol(av[3]);
	th->t_sleep = ft_atol(av[4]);
	th->died = 0;
	th->pid = malloc((sizeof(pid_t)) * (th->philos_count));
	if (!th->pid)
		exit_errors("pid malloc failed\n");
	sem_unlink("/init");
	th->init = sem_open("/init", O_CREAT | O_EXCL, 0644, 1);
	if (th->init == SEM_FAILED)
		exit_errors("sem_open init");
	sem_unlink("/forks");
	th->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, th->philos_count);
	if (th->forks == SEM_FAILED)
		exit_errors("sem_open forks");
	sem_unlink("/death");
	th->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 1);
	if (th->death == SEM_FAILED)
		exit_errors("sem_open death");
}

void	init_ph(t_philo *ph, t_threads *th, int ac, char **av)
{
	ph->id = 0;
	ph->th = th;
	ph->stamina = th->t_die;
	ph->t_last_meal = 0;
	if (ac == 6)
		ph->meals = ft_atol(av[5]);
	else
		ph->meals = -1;
}

void	init_structs(t_threads *th, t_philo *ph, int ac, char **av)
{
	init_th(th, av);
	init_ph(ph, th, ac, av);
}

void	exit_errors(char *s)
{
	ft_print(s, 2);
	exit(1);
}
