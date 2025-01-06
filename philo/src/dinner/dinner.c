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

void	*alone_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	wait_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex, &philo->table->nbr_running_threads);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!finished_simulation(philo->table))
		usleep(200);
	return (NULL);
}

void	*simulate_dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	increase_long(&philo->table->table_mutex, &philo->table->nbr_running_threads);
	while (!finished_simulation(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		xuleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
			xthread_handle(&table->philos[0].thread_id, alone_philo, &table->philos[0], CREATE);
	else
	{
		while (++i < table->philo_nbr)
			xthread_handle(&table->philos[i].thread_id, simulate_dinner, &table->philos[i], CREATE);
	}
	xthread_handle(&table->monitor, monitor_dinner, table, CREATE);
	table->start_simulation = gettime(MICROSECOND);
	set_bool(&table->table_mutex, &table->ready_threads, true);
	xthread_handle(&table->monitor, NULL, NULL, JOIN);
}
