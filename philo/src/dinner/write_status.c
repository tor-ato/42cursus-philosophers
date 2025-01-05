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

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND);
	if (finished_simulation(philo->table) || philo->full)
		return ;
	xmutex_handle(&philo->table->write_mutex, LOCK);
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status))
		printf("%lo %lo has taken a fork\n", elapsed, philo->thread_id);
	else if (EATING == status)
		printf("%lo %lo is eating\n", elapsed, philo->thread_id);
	else if (SLEEPING == status)
		printf("%lo %lo is sleeping\n", elapsed, philo->thread_id);
	else if (THINKING == status)
		printf("%lo %lo is thinking\n", elapsed, philo->thread_id);
	else if (DIED == status)
		printf("%lo %lo is died\n", elapsed, philo->thread_id);
	xmutex_handle(&philo->table->write_mutex, UNLOCK);
}
