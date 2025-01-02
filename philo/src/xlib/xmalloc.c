/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:08 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/02 16:49:45 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*xmalloc(size_t	bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		print_error_exit(E_MALLOC);
	return (ret);
}
