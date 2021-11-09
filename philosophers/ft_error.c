/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:02:51 by nabboudi          #+#    #+#             */
/*   Updated: 2021/11/09 17:02:53 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_values(void)
{
	if (g_all.data->n > __INT_MAX__ || g_all.data->time_to_die > __INT_MAX__)
		return (1);
	if (g_all.data->time_to_eat > __INT_MAX__
		|| g_all.data->time_to_sleep > __INT_MAX__)
		return (1);
	if (g_all.data->meals > __INT_MAX__)
		return (1);
	return (0);
}
