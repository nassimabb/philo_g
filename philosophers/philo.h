/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:04:23 by nabboudi          #+#    #+#             */
/*   Updated: 2021/11/09 17:04:23 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo
{
	size_t	n;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	meals;
}	t_philo;

typedef struct s_book
{
	pthread_t			philo;
	size_t				id;
	double				start;
	double				last_m;
	size_t				n_meals;
	int					flag;
	pthread_mutex_t		myfork;
	bool				is_eating;
	bool				is_sleeping;
}	t_book;

typedef struct s_global
{
	t_book			*wise;
	struct timeval	startp;
	pthread_mutex_t	print;
	pthread_mutex_t	inc_meal;
	t_philo			*data;
	int				ac;
}			t_global;

t_global	g_all;

double		current_timestamp(void);
void		print_to_screen(size_t id, char *msg);
void		sleeper( t_book *philo);
double		no_time(int id);
void		eat(t_book *philo);
int			check_philo(t_book *philo);
void		*routine(void *arg);
void		philo_func(char **av);
void		supervisor(void);
void		clean(void);
void		usleeper2(double time);
int			ft_atoi(const char *str);
int			ft_isdigit(char c);
int			check_args(char **av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
void		init_data(char **av);
int			check_values(void);

#endif
