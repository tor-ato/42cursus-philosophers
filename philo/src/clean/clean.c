/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:11:06 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 18:15:12 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		xmutex_handle(&philo->philo_mutex, DESTROY);
	}
	xmutex_handle(&table->write_mutex, DESTROY);
	xmutex_handle(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
