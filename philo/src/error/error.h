/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:55:09 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/02 16:50:13 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philo.h"

# include "unistd.h"
# include "stdlib.h"

# define USAGE "Usage: philo \
	number_of_philosophers \
	time_to_die time_to_eat time_to_sleep \
	[number_of_times_each_philosopher_must_eat]\n"

# define E_NON_NUMERIC_ARG		"Error: non-numeric argument\n"
# define E_TOO_LARGE_ARG		"Error: too large argument\n"
# define E_ZERO_ARG				"Error: each argument must be positive\n"
# define E_NON_MINUS_ARG		"Error: non-minus argurment\n"
# define E_INTMAX_LIMT_ARG		"Error: INT_MAX is limit\n"
# define E_MAJOR_SIXTY_MS_ARG	"Error: Use timestamp major than 60ms\n"

void		print_error_exit(const char *message);

#endif
