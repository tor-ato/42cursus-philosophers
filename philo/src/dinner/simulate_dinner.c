/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:39:55 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/07 16:40:12 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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
		xusleep(philo->table->time_to_sleep, philo->table);
		write_status(THINKING, philo, DEBUG_MODE);
		thinking(philo);
	}
	return (NULL);
}
