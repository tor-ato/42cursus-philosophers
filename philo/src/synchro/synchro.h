/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:50:59 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 15:58:37 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNCHRO_H
# define SYNCHRO_H
# include "philo.h"

void	wait_threads(t_table *table);
void	increase_long(t_mtx *mutex, long *value);
bool	runinng_treads(t_mtx *mutex, long *runinng_treads, long philo_nbr);
#endif
