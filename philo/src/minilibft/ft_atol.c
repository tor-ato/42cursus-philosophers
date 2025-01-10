/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:40:41 by tkitahar          #+#    #+#             */
/*   Updated: 2024/12/28 18:43:19 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error(E_NON_MINUS_ARG);
	if (!ft_isdigit(*str))
		print_error(E_NON_NUMERIC_ARG);
	number = str;
	while (ft_isdigit(*str++))
		++len;
	if (len > 10)
		print_error(E_INTMAX_LIMT_ARG);
	return (number);
}

long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (ft_isdigit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		print_error(E_INTMAX_LIMT_ARG);
	return (num);
}
