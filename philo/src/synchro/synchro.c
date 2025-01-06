/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:49:36 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 15:57:54 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->ready_threads))
		;
}

bool	runinng_treads(t_mtx *mutex, long *runinng_treads, long philo_nbr)
{
	bool	ret;

	ret = false;
	xmutex_handle(mutex, LOCK);
	if (*runinng_treads == philo_nbr)
		ret = true;
	xmutex_handle(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mtx *mutex, long *value)
{
	xmutex_handle(mutex, LOCK);
	(*value)++;
	xmutex_handle(mutex, UNLOCK);
}
