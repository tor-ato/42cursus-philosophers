/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:34:34 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/10 16:32:07 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void write_satatus_debug(t_philo_status status, t_philo *philo)
{
	if (TAKE_FIRST_FORK == status)
		printf("%ld  %d has teken the No.%d fork.\n",gettime(MILLISECOND), philo->id, philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status)
		printf("%ld  %d has teken the No.%d fork.\n",gettime(MILLISECOND), philo->id, philo->second_fork->fork_id);
	else if (EATING == status)
		printf("%ld  %d is eating %ld.\n",gettime(MILLISECOND) ,philo->id, philo->meals_counter);
	else if (SLEEPING == status)
		printf("%ld  %d is sleeping.\n",gettime(MILLISECOND) , philo->id);
	else if (THINKING == status)
		printf("%ld  %d is thinking.\n",gettime(MILLISECOND) , philo->id);
	else if (DIED == status)
		printf("%ld  %d died.\n",gettime(MILLISECOND) , philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	if ((finished_simulation(philo->table) || philo->full) && status != DIED)
			return ;
	xmutex_handle(&philo->table->write_mutex, LOCK);
	if (!debug)
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status))
			printf("%ld %d has taken a fork\n", gettime(MILLISECOND), philo->id);
		else if (EATING == status)
			printf("%ld %d is eating\n", gettime(MILLISECOND), philo->id);
		else if (SLEEPING == status)
			printf("%ld %d is sleeping\n", gettime(MILLISECOND), philo->id);
		else if (THINKING == status)
			printf("%ld %d is thinking\n", gettime(MILLISECOND), philo->id);
		else if (DIED == status)
			printf("%ld %d died\n", gettime(MILLISECOND), philo->id);
	}
	else
		write_satatus_debug(status, philo);
	xmutex_handle(&philo->table->write_mutex, UNLOCK);
}
