/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:26:29 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/02/14 18:21:12 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	int			id;
	int			philo_n;
	int			eat_times;
	int			meals_eaten;

	pthread_t	thread;
	size_t		tte;
	size_t		tts;
	size_t		ttd;

	size_t		start_time;
	size_t		last_meal;

	sem_t		*forks;
	sem_t		*dead;
	sem_t		*write_lock;

}				t_philo;

int				check_valid_av(t_philo *philo, char **av);
int				check_empty_av(char **av);
long			ft_atol(const char *s);
void			ft_print(char *s, int fd);
size_t			get_current(void);
int				ft_usleep(size_t ms);
void			set_semaphores(t_philo *philo);

void			print_action(t_philo *philo, char *action);
void			*monitor(void *p);

void			philo_rout(t_philo *philo);

#endif