/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:41:18 by tkitahar          #+#    #+#             */
/*   Updated: 2024/12/28 22:09:22 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include "philo.h"

#include <errno.h>
#include <limits.h>
#include <stddef.h>

int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);

#endif
