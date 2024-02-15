/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:28:31 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/02/14 18:21:04 by amarzouk         ###   ########.fr       */
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

int	check_valid_av(t_philo *philo, char **av)
{
	if (error_syntax(av[1]) || (ft_atol(av[1]) >= 201) || (ft_atol(av[1]) <= 0))
		return (printf("Invalid philo number\n"), 1);
	if (error_syntax(av[2]) || ft_atol(av[2]) < 60)
		return (printf("Invalid time to die\n"), 1);
	if (error_syntax(av[3]) || ft_atol(av[3]) < 60)
		return (printf("Invalid time to eat\n"), 1);
	if (error_syntax(av[4]) || ft_atol(av[4]) < 60)
		return (printf("Invalid time to sleep\n"), 1);
	if (av[5] && (error_syntax(av[5]) || ft_atol(av[5]) <= 0))
		return (printf("Invalid number of eating\n"), 1);
	philo->philo_n = ft_atol(av[1]);
	philo->ttd = ft_atol(av[2]);
	philo->tte = ft_atol(av[3]);
	philo->tts = ft_atol(av[4]);
	if (av[5])
		philo->eat_times = ft_atol(av[5]);
	else
		philo->eat_times = -1;
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
