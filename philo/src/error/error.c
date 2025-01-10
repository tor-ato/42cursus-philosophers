/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:17:33 by tkitahar          #+#    #+#             */
/*   Updated: 2024/12/28 22:10:26 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	print_error(const char *message)
{
	size_t		len;

	len = ft_strlen(message);
	write(STDERR_FILENO, message, len);
	return (EXIT_FAILURE);
}
