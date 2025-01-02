/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:42:59 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/02 19:01:39 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XLIB_H
# define XLIB_H
# include "philo.h"

void	*xmalloc(size_t	bytes);
void	xmutex_handle(t_mtx *mutex, t_opcode opcode);
void	xthread_handle(pthread_t *thread, void *(*func)(void *), \
					void *data, t_opcode opcode);

# define E_MALLOC "Error: malloc"
# define E_MUTEX_OPCODE "Error: Wrong opcode for mutex handle"

#endif
