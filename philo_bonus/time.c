/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:01 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/09 10:38:24 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_time_diff(struct timeval ta)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000 + tm.tv_usec / 1000) - (ta.tv_sec * 1000
			+ ta.tv_usec / 1000));
}

void	ft_usleep(t_philo *ph, int time)
{
	struct timeval	before;
	struct timeval	end;

	gettimeofday(&before, NULL);
	gettimeofday(&end, NULL);
	while (((end.tv_sec * 1000 + end.tv_usec / 1000) - (before.tv_sec * 1000
				+ before.tv_usec / 1000)) < time)
	{
		ft_die(ph);
		usleep(100);
		ft_die(ph);
		gettimeofday(&end, NULL);
	}
}
