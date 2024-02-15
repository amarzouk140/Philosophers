/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:34:14 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/02/15 08:12:04 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sleep_think(t_philo *philo)
{
	print_action(philo, "is sleeping 🛌😴💤");
	ft_usleep(philo->tts);
}

void	philo_rout(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		sem_wait(philo->forks);
		print_action(philo, "has taken a fork 🍴");
		if (philo->philo_n == 1)
		{
			ft_usleep(philo->ttd);
			sem_post(philo->forks);
			return (print_action(philo, "died 💀"), exit(0));
		}
		sem_wait(philo->forks);
		print_action(philo, "has taken a fork 🍴");
		print_action(philo, "is eating 🍽️ 😋");
		ft_usleep(philo->tte);
		philo->last_meal = get_current();
		philo->meals_eaten++;
		sem_post(philo->forks);
		sem_post(philo->forks);
		sleep_think(philo);
		if (philo->eat_times != -1 && philo->meals_eaten >= philo->eat_times)
			return (exit(0));
		print_action(philo, "is thinking 🧠🤫");
	}
}

void	exit_errors(char *s)
{
	ft_print(s, 2);
	exit(1);
}

void	set_semaphores(t_philo *philo)
{
	sem_unlink("forks");
	sem_unlink("write_lock");
	sem_unlink("dead");
	philo->forks = sem_open("forks", O_CREAT, 0644, philo->philo_n);
	if (philo->forks == SEM_FAILED)
		exit_errors("sem_open");
	philo->write_lock = sem_open("write_lock", O_CREAT, 0644, 1);
	if (philo->write_lock == SEM_FAILED)
		exit_errors("sem_open");
	philo->dead = sem_open("dead", O_CREAT, 0644, 1);
	if (philo->dead == SEM_FAILED)
		exit_errors("sem_open");
}
