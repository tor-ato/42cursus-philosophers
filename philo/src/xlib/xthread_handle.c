/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xthread_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:40:29 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/03 14:17:23 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	else if (EAGAIN == status)
		print_error("Error: No resources to creat another thread.");
	else if (EPERM == status)
		print_error("Error: The caller does not have approrpriate "
			"permission");
	else if (EINVAL == status && CREATE == opcode)
		print_error("Error: The value specified by atter is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		print_error("Error: No thread could be found corresponding to that"
			"specified by the given thread ID. tread.");
	else if (EDEADLK == status)
		print_error("Error: A deadlock was detected ore the value of"
			"thread specifies the callting thread.");
}

void	xthread_handle(pthread_t *thread, void *(*func)(void *), \
					void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, func, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		print_error(E_MUTEX_OPCODE);
}
