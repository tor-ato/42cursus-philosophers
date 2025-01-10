/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:17:43 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/10 16:21:31 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo)
{
	millisecond	elapsed;
	millisecond	t_to_die;

	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
	t_to_die = philo->table->time_to_die / ONE_THOUSAND;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table *table;
	t_philo *philo;

	table = (t_table *)data;
	while (!runinng_treads(&table->table_mutex, &table->nbr_running_threads, table->philo_nbr))
		;
	while (!finished_simulation(table))
	{
		i = -1;
		while (++i < table->philo_nbr && !finished_simulation(table))
		{
			philo = table->philos + i; 
			if (get_bool(&philo->philo_mutex, &philo->full))
				return (NULL);
			if (philo_died(philo))
			{
				set_bool(&table->table_mutex, &table->end_simulation, true);
				write_status(DIED, table->philos + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}
