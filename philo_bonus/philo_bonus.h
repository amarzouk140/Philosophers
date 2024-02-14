/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:27:20 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/14 16:15:37 by amarzouk         ###   ########.fr       */
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
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_threads
{
	int				philos_count;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				died;
	int				meals_to_eat;
	int				ate;
	pid_t			*pid;
	sem_t			*init;
	sem_t			*forks;
	sem_t			*death;
	sem_t			*meal;
}					t_threads;

typedef struct s_philosopher
{
	int				id;
	int				t_last_meal;
	int				stamina;
	struct timeval	t_born;
	t_threads		*th;
}					t_philo;

void				ft_print(char *s, int fd);
long				ft_atol(const char *s);
int					check_valid_av(char **av);
int					check_empty_av(char **av);
void				exit_errors(char *s);

void				init_structs(t_threads *th, t_philo *ph, int ac, char **av);
void				ft_create_process(t_philo *ph);

void				ft_usleep(t_philo *ph, int time);
int					get_time_diff(struct timeval ta);
void				ft_check_forks(t_philo *ph);
void				ft_eat(t_philo *ph);
int					ft_die(t_philo *ph);
void				ft_caseof1(t_philo *ph);
void				ft_kill_them_all(t_philo *ph);

void				ft_destroy_sem(t_threads *th);
void				ft_print_status(t_philo *ph, char *str);

#endif