/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:29:48 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/09 09:30:13 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && (*s
					- 48) > LONG_MAX % 10))
			return (-1);
		result = result * 10 + (*s++ - 48);
	}
	if (result > INT_MAX || result < INT_MIN)
		return (-1);
	else
		return (result * sign);
}

static int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == 32 || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != 32)
			return (1);
	}
	return (0);
}

int	check_valid_av(char **av)
{
	if (error_syntax(av[1]) || (ft_atol(av[1]) >= 201) || (ft_atol(av[1]) <= 0))
		return (ft_print("Invalid philo number 🧐⛔\n", 2), 1);
	if (error_syntax(av[2]) || ft_atol(av[2]) < 60)
		return (ft_print("Invalid time to die 🧐⛔\n", 2), 1);
	if (error_syntax(av[3]) || ft_atol(av[3]) < 60)
		return (ft_print("Invalid time to eat 🧐⛔\n", 2), 1);
	if (error_syntax(av[4]) || ft_atol(av[4]) < 60)
		return (ft_print("Invalid time to sleep 🧐⛔\n", 2), 1);
	if (av[5] && (error_syntax(av[5]) || ft_atol(av[5]) <= 0))
		return (ft_print("Invalid number of eating 🧐⛔\n", 2), 1);
	return (0);
}

int	check_empty_av(char **av)
{
	int	j;
	int	y;

	j = 1;
	y = 0;
	while (av[j])
	{
		y = 0;
		while (av[j][y])
		{
			if (av[j][y] != 32 && av[j][y] != '\t')
				break ;
			y++;
		}
		if (!av[j][y])
			return (1);
		j++;
	}
	return (0);
}
