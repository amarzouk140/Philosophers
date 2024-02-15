/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:10 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/15 14:42:59 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_unlink(void)
{
	sem_unlink("forks");
	sem_unlink("write_lock");
	sem_unlink("dead");
	sem_unlink("meals_lock");
	sem_unlink("read_lock");
	sem_unlink("foks");
}

void	ft_destroy_sem(t_philo *th)
{
	sem_close(th->dead);
	sem_close(th->forks);
	sem_close(th->write_lock);
	sem_close(th->meals_lock);
	sem_close(th->read_lock);
	sem_close(th->foks);
	ft_sem_unlink();
}

void	set_semaphores(t_philo *philo)
{
	int	chk;

	chk = 0;
	if (philo->philo_n % 2)
		chk = 1;
	chk += philo->philo_n / 2;
	ft_sem_unlink();
	philo->forks = sem_open("forks", O_CREAT, 0644, chk);
	if (philo->forks == SEM_FAILED)
		exit_errors("sem_open");
	philo->foks = sem_open("foks", O_CREAT, 0644, philo->philo_n / 2);
	if (philo->foks == SEM_FAILED)
		exit_errors("sem_open");
	philo->write_lock = sem_open("write_lock", O_CREAT, 0644, 1);
	if (philo->write_lock == SEM_FAILED)
		exit_errors("sem_open");
	philo->dead = sem_open("dead", O_CREAT, 0644, 1);
	if (philo->dead == SEM_FAILED)
		exit_errors("sem_open");
	philo->meals_lock = sem_open("meals_lock", O_CREAT, 0644, 1);
	if (philo->meals_lock == SEM_FAILED)
		exit_errors("sem_open");
	philo->read_lock = sem_open("read_lock", O_CREAT, 0644, 1);
	if (philo->read_lock == SEM_FAILED)
		exit_errors("sem_open");
}
