/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:21:54 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 18:23:02 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_table *table)
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
	xthread_handle(&table->monitor, monitor_dinner, table, CREATE);
	table->start_simulation = gettime(MICROSECOND);
	set_bool(&table->table_mutex, &table->ready_threads, true);
	xthread_handle(&table->monitor, NULL, NULL, JOIN);
}
