/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:02:33 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 16:27:54 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	xmutex_handle(mutex, LOCK);
	*dest = value;
	xmutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	xmutex_handle(mutex, LOCK);
	ret = *value;
	xmutex_handle(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, bool *dest, long value)
{
	xmutex_handle(mutex, LOCK);
	*dest = value;
	xmutex_handle(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	xmutex_handle(mutex, LOCK);
	ret = *value;
	xmutex_handle(mutex, UNLOCK);
	return (ret);
}

bool	finished_simulation(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
