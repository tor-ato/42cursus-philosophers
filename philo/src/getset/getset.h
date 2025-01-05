/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:07:34 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 16:25:56 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETSET_H
# define  GETSET_H
# include "philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, bool *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	finished_simulation(t_table *table);
#endif
