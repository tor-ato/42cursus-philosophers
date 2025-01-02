/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmutex_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:52:49 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/02 18:06:29 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		print_error_exit("Error: The value specified by mutex is invalid.");
	else if (EINVAL == status && INIT == opcode)
		print_error_exit("Error: The value specified by atter is invalid.");
	else if (EDEADLK == status)
		print_error_exit("Error: A dead lock would occer if the thread blocked wating for mutex.");
	else if (EPERM == status)
		print_error_exit("Error: The current thread does not hold alock on mutex.");
	else if (ENOMEM == status)
		print_error_exit("Error: The process cannnot allocate enough memory to creat another mutex.");
	else if (EBUSY == status)
		print_error_exit("Error: Mutex is lockded.");
}

void	xmutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		print_error_exit(E_MUTEX_OPCODE);
}
