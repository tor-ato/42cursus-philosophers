/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:34:34 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 18:34:35 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void write_satatus_debug(t_philo_status status, t_philo *philo)
{
	if (TAKE_FIRST_FORK == status)
		printf("ph_id:%d has teken the No.%d fork\n", philo->id, philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status)
		printf("ph_id:%d has teken the No.%d fork\n", philo->id, philo->second_fork->fork_id);
	else if (EATING == status)
		printf("ph_id:%d is eating %ld\n", philo->id, philo->meals_counter);
	else if (SLEEPING == status)
		printf("ph_id:%d %ld is sleeping\n", philo->id, philo->thread_id);
	else if (THINKING == status)
		printf("ph_id:%d %ld is thinking\n", philo->id, philo->thread_id);
	else if (DIED == status)
		printf("ph_id:%d has died\n", philo->id);
	else if (DEEP == status)
		printf("ph_id:%d is DEEP\n", philo->id);
	else if (SHALLOW == status)
		printf("ph_id:%d is SHALLOW\n", philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if ((finished_simulation(philo->table) || philo->full) && status != DIED)
	{
			printf("ph_id:%d returned whith \n", philo->id);
			return ;
	}
	xmutex_handle(&philo->table->write_mutex, LOCK);
	if (!debug)
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status))
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status)
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status)
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status)
			printf("%ld %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf("%ld %d is died\n", elapsed, philo->id);
	}
	else
		write_satatus_debug(status, philo);
	xmutex_handle(&philo->table->write_mutex, UNLOCK);
}
