/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:21:54 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/10 20:55:52 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_simulate_dinners(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
			xthread_handle(&table->philos[0].thread_id, alone_philo, \
				  &table->philos[0], CREATE);
	else
	{
		while (++i < table->philo_nbr)
			xthread_handle(&table->philos[i].thread_id, simulate_dinner, \
				  &table->philos[i], CREATE);
	}
}

static void start_monitor_dinners(t_table *table)
{
	xthread_handle(&table->monitor, monitor_dinner, table, CREATE);
}

static void set_start_time(t_table *table)
{
	table->start_simulation = gettime(MILLISECOND);
}

static void set_ready_threads(t_table *table)
{
	set_bool(&table->table_mutex, &table->ready_threads, true);
}

void	start_dinner(t_table *table)
{
	start_simulate_dinners(table);
	start_monitor_dinners(table);
	set_start_time(table);
	set_ready_threads(table);
	join_threads(table);
}
