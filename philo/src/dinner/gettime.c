/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:55:57 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:10 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error_exit("Error: Gettimeofday.");
	if (time_code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / ONE_MILLION));
	else if (time_code == MILLISECOND)
		return ((tv.tv_sec * ONE_THOUSAND) + (tv.tv_usec / ONE_THOUSAND));
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * ONE_MILLION) + tv.tv_usec);
	else
		print_error_exit("Error: Wrong input to gettime.");
	return (1334);
}
