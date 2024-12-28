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

static int	read_up_to_sign(const char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
	if (**s && **s == '-')
	{
		(*s)++;
		return (-1);
	}
	if (**s && **s == '+')
		(*s)++;
	return (1);
}

static int is_overflow(int sign, unsigned long num, unsigned long x)
{
    if (sign == 1)
        return (LONG_MAX / 10 < num || LONG_MAX - num * 10 < x);
    else
        return (num > LONG_MIN / -10 || x > -(LONG_MIN + num * 10));
}

long	ft_atol(const char *str)
{
	int				sign;
	unsigned long	num;
	unsigned long	x;

	num = 0;
	sign = read_up_to_sign(&str);
	while (*str && ft_isdigit(*str))
	{
		x = *str++ - '0';
		if (is_overflow(sign, num, x))
		{
			errno = ERANGE;
			if (sign > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + x;
	}
	return (sign * num);
}
