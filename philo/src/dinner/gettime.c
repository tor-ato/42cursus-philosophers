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

#include "philo.h"

long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error("Error: Gettimeofday.");
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / ONE_MILLION));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * ONE_THOUSAND) + (tv.tv_usec / ONE_THOUSAND));
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * ONE_MILLION) + tv.tv_usec);
	else
		print_error("Error: Wrong input to gettime.");
	return (1334);
}
