/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:55:15 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/10 20:59:00 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		xthread_handle(&(table->philos + i)->thread_id, NULL, NULL, JOIN);
	xthread_handle(&table->monitor, NULL, NULL, JOIN);
}
