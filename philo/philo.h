/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:00:35 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/12 17:40:23 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAXIMUM_P 200

typedef struct s_params
{
	int				philo_count;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	int				tte_times;
}					t_params;

typedef struct s_philo
{
	t_params		*params;
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	pthread_mutex_t	forks[MAXIMUM_P];
	t_philo			philos[MAXIMUM_P];
	t_params		params;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_program;

int					check_empty_av(char **av);
int					check_valid_av(char **av);
long				ft_atol(const char *s);
void				ft_print(char *s, int fd);

int					init_philo(t_program *data, int ac, char **av);
int					init_forks(t_program *program, t_params *params);
void				philo_data(t_program *program, t_params *params);

void				*routine(void *arg);
size_t				get_current(void);
void				print_message(t_philo *philo, char *message);
int					dead(t_philo *philo);

int					init_thread(t_philo *philos, t_program *data);
int					create_thread(t_philo *philos, t_program *data);
int					join_thread(t_philo *philos, t_program *data);
int					destroy(t_program *program);
int					ft_usleep(size_t milliseconds, t_philo *philo);
void				monitor(t_philo *philos);
#endif