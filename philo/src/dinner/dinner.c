/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:21:54 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 21:22:34 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	*simulate_dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	while (!finished_simulation(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		xuleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
			;
	else
	{
		while (++i < table->philo_nbr)
			xthread_handle(&table->philos[i].thread_id, simulate_dinner, &table->philos[i], CREATE);
	}
	table->start_simulation = gettime(MICROSECOND);
	set_bool(&table->table_mutex, &table->ready_threads, true);
}
