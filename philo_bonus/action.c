/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:41:05 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/14 10:02:39 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_status(t_philo *ph, char *str)
{
	if (ph->th->died == 1 && ph->meals_to_eat == 0)
		exit(1);
	printf("%d %d %s\n", get_time_diff(ph->t_born), ph->id, str);
}

void	ft_check_forks(t_philo *ph)
{
	ft_die(ph);
	sem_wait(ph->th->forks); // Test 4 310 200 100. One philosopher should die.
	ft_die(ph);
	ft_print_status(ph, "has taken a fork 🍴");
	ft_die(ph);
	sem_wait(ph->th->forks);
	ft_die(ph);
	ft_print_status(ph, "has taken a fork 🍴");
	ft_eat(ph);
	sem_post(ph->th->forks);
	sem_post(ph->th->forks);
	ft_die(ph);
}

void	ft_eat(t_philo *ph)
{
	ft_print_status(ph, "is eating 🍽️");
	ft_usleep(ph, ph->th->t_eat);
	ph->t_last_meal = get_time_diff(ph->t_born);
	if (ph->meals_to_eat > 0)
		ph->meals_to_eat--;
}

int	ft_die(t_philo *ph)
{
	if (ph->th->died == 1 || ph->meals_to_eat == 0)
		exit(1);
	sem_wait(ph->th->death);
	if (ph->stamina < get_time_diff(ph->t_born) - ph->t_last_meal
		&& !ph->th->died)
	{
		ft_print_status(ph, "died 💀");
		ph->th->died = 1;
		exit(1);
	}
	sem_post(ph->th->death);
	return (0);
}

void	ft_kill_them_all(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->th->philos_count)
		kill(ph->th->pid[i], SIGKILL);
}
