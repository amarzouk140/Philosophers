/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:26:38 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/13 10:06:23 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_destroy_sem(t_threads *th)
{
	sem_close(th->init);
	sem_close(th->forks);
	sem_close(th->death);
	sem_unlink("/init");
	sem_unlink("/forks");
	sem_unlink("/death");
	free(th->pid);
}

int	main(int ac, char **av)
{
	t_threads	threads;
	t_philo		philos;
	int			i;
	int			status;

	if (ac != 5 && ac != 6)
		return (ft_print("invalid number of inputs 😐⛔\n", 2), 2);
	if (check_empty_av(av))
		return (ft_print("empty argument deducted 😐⛔\n", 2), 2);
	if (check_valid_av(av))
		return (2);
	init_structs(&threads, &philos, ac, av);
	sem_wait(threads.init);
	ft_create_process(&philos);
	i = -1;
	status = 0;
	while (++i < threads.philos_count)
	{
		waitpid(-1, &status, 0);
		if (status)
			ft_kill_them_all(&philos);
	}
	ft_destroy_sem(&threads);
	return (0);
}
