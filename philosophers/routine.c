/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:05:06 by nabboudi          #+#    #+#             */
/*   Updated: 2021/11/09 17:05:06 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	check_philo(t_book *philo)
{
	size_t	id;

	id = philo->id;
	if (no_time(id) > g_all.data->time_to_die)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_book	*philo;

	philo = (t_book *)arg;
	if (g_all.ac == 5)
		g_all.wise[philo->id].n_meals = 1;
	g_all.wise[philo->id].start = current_timestamp();
	while (true)
	{
		g_all.wise[philo->id].is_eating = false;
		eat(philo);
		sleeper(philo);
		print_to_screen(philo->id, "is thinking");
	}
	return (arg);
}

void	small_init(char **av)
{
	g_all.data = (t_philo *)malloc(sizeof(t_philo));
	g_all.data->n = ft_atoi(av[0]);
	g_all.data->time_to_die = ft_atoi(av[1]);
	g_all.data->time_to_eat = ft_atoi(av[2]);
	g_all.data->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
		g_all.data->meals = ft_atoi(av[4]);
	else
		g_all.data->meals = 1;
	g_all.wise = (t_book *)malloc(sizeof(t_book) * (g_all.data->n + 1));
	pthread_mutex_init(&g_all.print, NULL);
	pthread_mutex_init(&g_all.inc_meal, NULL);
	gettimeofday(&g_all.startp, NULL);
}

void	init_data(char **av)
{
	size_t	i;

	i = 1;
	small_init(av);
	while (i < g_all.data->n + 1)
	{
		g_all.wise[i - 1].n_meals = 1;
		g_all.wise[i - 1].id = i;
		g_all.wise[i - 1].flag = 0;
		g_all.wise[i - 1].is_eating = false;
		if (pthread_mutex_init(&(g_all.wise[i - 1].myfork), NULL) != 0)
			break ;
		i++;
	}
}
