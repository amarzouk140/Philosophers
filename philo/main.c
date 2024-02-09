/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:03:41 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/08 14:11:35 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program	data;

	if (ac != 5 && ac != 6)
		return (ft_print("invalid number of inputs 😐⛔\n", 2), 2);
	if (check_empty_av(av))
		return (ft_print("empty argument deducted 😐⛔\n", 2), 2);
	if (check_valid_av(av))
		return (2);
	init_philo(&data, ac, av);
}
