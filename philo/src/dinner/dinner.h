/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:08 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 21:22:52 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philo.h"
long	gettime(t_time_code time_code);
void	write_status(t_philo_status status, t_philo *philo);
void	eat(t_philo *philo);
void	thinking(t_philo *philo);
#endif
