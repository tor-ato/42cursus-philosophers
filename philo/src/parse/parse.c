/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:47:37 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/03 14:07:05 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * MS;
	table->time_to_eat = ft_atol(av[3]) * MS;
	table->time_to_sleep = ft_atol(av[4]) * MS;
	if (table->time_to_die < SIXTY_MS || \
		table->time_to_eat < SIXTY_MS || \
		table->time_to_sleep < SIXTY_MS)
		print_error_exit(E_MAJOR_SIXTY_MS_ARG);
	if (!av[5])
		table->nbr_limit_meals = -1;
	else
		table->nbr_limit_meals = ft_atol(av[5]);
}
