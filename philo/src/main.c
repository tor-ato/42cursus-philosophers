/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:57:35 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 18:18:37 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"

int	ac_error(int ac)
{
	if (ac != 5 && ac != 6)
	{
		print_error(USAGE);
		return (AC_ERROR);
	}
	return (AC_SUCCESS);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac_error(ac) == AC_ERROR)
		return (1);
	if (parse_input(&table, av) == PARSE_ERROR)
		return (2);
	if (init_table(&table) == INIT_FALURE)
		return (3);
	start_dinner(&table);
	clean(&table);
	return (EXIT_SUCCESS);
}
