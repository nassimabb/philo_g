/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:05:23 by nabboudi          #+#    #+#             */
/*   Updated: 2021/11/09 17:05:24 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"philo.h"

double	current_timestamp(void)
{
	struct timeval	watch;

	gettimeofday(&watch, NULL);
	return ((watch.tv_sec * 1000 ) + (watch.tv_usec / 1000));
}

void	usleeper2(double time)
{
	double	now;

	now = current_timestamp();
	usleep(time * 1000 * 0.85);
	while (current_timestamp() < now + time)
		continue ;
}

void	sleeper( t_book *philo)
{
	print_to_screen(philo->id, "is sleeping");
	usleeper2(g_all.data->time_to_sleep);
}

double	no_time(int id)
{
	if (id == -1)
		return (current_timestamp()
			-((g_all.startp.tv_sec * 1000) + (g_all.startp.tv_usec / 1000)));
	return (current_timestamp() - g_all.wise[id].start);
}

void	print_to_screen(size_t id, char *msg)
{
	pthread_mutex_lock(&g_all.print);
	printf("%d %ld %s\n", (int)no_time(-1), id, msg);
	if (strncmp(msg, "is dead", (long unsigned int)7) != 0)
		pthread_mutex_unlock(&g_all.print);
}
