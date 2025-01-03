/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:57:35 by tkitahar          #+#    #+#             */
/*   Updated: 2024/12/28 22:03:03 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	(void) av;
	t_table	table;

	if (ac != 5 && ac != 6)
		print_error_exit(USAGE);
	parse_input(&table, av);
	init_table(&table);
	// start_dinner(&table);
	// clean_data(&table);
	return (0);
}
