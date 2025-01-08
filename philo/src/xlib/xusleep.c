/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xusleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:55 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 18:22:21 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	xusleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = gettime(MILLISECOND);
	printf("xusleep start xusleep\n");
	while (gettime(MILLISECOND) - start < usec)
	{
		if (finished_simulation(table))
			break;
		elapsed = gettime(MILLISECOND) - start;
		rem = usec - elapsed;
		if (rem > ONE_THOUSAND)
		{
			printf("aaa\n");
			// usleep(rem / 2);
			usleep(100);
			printf("bbb\n");
		}
		else
		{
			while (gettime(MILLISECOND) - start < usec)
				;
		}
	}
}
