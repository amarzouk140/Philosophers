/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:37:53 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/02/15 09:06:39 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_destroy_sem(t_philo *th)
{
	sem_close(th->dead);
	sem_close(th->forks);
	sem_close(th->write_lock);
	sem_close(th->meals_lock);
	sem_close(th->read_lock);
	sem_unlink("dead");
	sem_unlink("forks");
	sem_unlink("write_lock");
	sem_unlink("meals_lock");
	sem_unlink("read_lock");
}

void	monitor_process(t_philo *philo, pid_t *pid)
{
	int	i;
	int	j;

	i = 0;
	while (i < philo->philo_n)
	{
		waitpid(-1, &j, 0);
		if (j != 0)
		{
			i = 0;
			while (i < philo->philo_n)
			{
				kill(pid[i], SIGKILL);
				i++;
			}
		}
		i++;
	}
}

int	philo_init(t_philo *philo)
{
	philo->id += 1;
	sem_wait(philo->meals_lock);
	philo->last_meal = get_current();
	sem_post(philo->meals_lock);
	philo->meals_eaten = 0;
	if (pthread_create(&philo->thread, NULL, &monitor, philo))
	{
		ft_destroy_sem(philo);
		exit_errors("pthread_create failed");
	}
	pthread_detach(philo->thread);
	philo_rout(philo);
	return (0);
}

int	philo_create(t_philo *philo)
{
	int		i;
	pid_t	pid[200];

	i = 0;
	philo->start_time = get_current();
	philo->id = 0;
	while (i < philo->philo_n)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			return (ft_destroy_sem(philo), exit_errors("fork failed"), 1);
		}
		else if (pid[i] == 0)
		{
			philo->id = i;
			break ;
		}
		i++;
	}
	if (pid[philo->id] == 0 && !philo_init(philo))
		return (1);
	else
		monitor_process(philo, pid);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac != 5 && ac != 6)
		return (printf("invalid number of inputs\n"), 1);
	if (check_empty_av(av))
		return (printf("empty argument deducted\n"), 1);
	if (check_valid_av(&philo, av))
		return (1);
	set_semaphores(&philo);
	philo_create(&philo);
	ft_destroy_sem(&philo);
	return (0);
}
