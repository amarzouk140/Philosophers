/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:00:20 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/14 17:05:15 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_caseof1(t_philo *ph)
{
	sem_wait(ph->th->forks);
	gettimeofday(&ph->t_born, NULL);
	printf("%d %d has taken a fork 🍴\n", get_time_diff(ph->t_born), ph->id);
	ft_usleep(ph, ph->th->t_eat);
	sem_post(ph->th->forks);
	gettimeofday(&ph->t_born, NULL);
	ft_usleep(ph, ph->th->t_die);
	printf("%d %d died 💀\n", get_time_diff(ph->t_born), ph->id);
}

// int	ft_odd_pair(t_philo *ph)
// {
// 	// static int	i = 0;

// 	// while (i++ < ph->th->philos_count)
// 	// 	usleep(50);
// 	if (ph.id % 2 == 0)
// 		ft_usleep(&ph, 50);
// 	gettimeofday(&ph->t_born, NULL);
// 	return (1);
// }

void	*routine(void *arg)
{
	t_philo	ph;

	ph = *(t_philo *)arg;
	sem_post(ph.th->init);
	if (ph.th->philos_count == 1)
		return (ft_caseof1(&ph), NULL);
	if (ph.id % 2 == 0)
		ft_usleep(&ph, 50);
	gettimeofday(&ph.t_born, NULL);
	while (!ft_die(&ph))
	{
		sem_wait(ph.th->forks);
		ft_print_status(&ph, "has taken a fork 🍴");
		sem_wait(ph.th->forks);
		ft_print_status(&ph, "has taken a fork 🍴");
		ft_print_status(&ph, "is eating 🍽️");
		ft_usleep(&ph, ph.th->t_eat);
		ph.t_last_meal = get_time_diff(ph.t_born);
		sem_post(ph.th->forks);
		sem_post(ph.th->forks);
		ft_print_status(&ph, "is sleeping 🛌😴💤");
		ft_usleep(&ph, ph.th->t_sleep);
		ft_print_status(&ph, "is thinking 🧠🤫");
		sem_wait(ph.th->meal);
		ph.th->ate++;
		sem_post(ph.th->meal);
		// ft_check_forks(&ph);
		// ft_usleep(&ph, ph.th->t_sleep);

	}
	return (NULL);
}

void	ft_create_process(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->th->philos_count)
	{
		ph->th->pid[i] = fork();
		ph->id = i + 1;
		if (ph->th->pid[i] == 0)
			routine(ph);
	}
}
