/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:20:02 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/02 19:31:46 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position +1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position +1) % philo_nbr];
	}
}

static void	init_philo(t_table *table)
{
	int philo_position;
	t_philo *philo;

	philo_position = -1;
	while (++philo_position < table->philo_nbr)
	{
		philo = &(table->philos[philo_position]);
		philo->id = philo_position + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		assign_forks(philo, table->forks, philo_position);
	}
}

void	init_data(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
	table->philos = xmalloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = xmalloc(sizeof(t_fork) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		xmutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	init_philo(table);
}
