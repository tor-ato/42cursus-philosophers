/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:38:05 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 21:18:28 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static void	take_forks(t_philo *philo)
{
	xmutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	xmutex_handle(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
}

static void	drop_forks(t_philo *philo)
{
	xmutex_handle(&philo->first_fork->fork, UNLOCK);
	xmutex_handle(&philo->second_fork->fork, UNLOCK);
}

static void	do_eat(t_philo *philo)
{
	set_long(&philo->philo_mutex, philo->last_meal_time, gettime(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo);
	xuleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0 && \
		philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	do_eat(philo);
	drop_forks(philo);
}
