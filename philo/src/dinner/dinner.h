/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:08 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/06 18:19:13 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philo.h"
long	gettime(t_time_code time_code);
void	write_status(t_philo_status status, t_philo *philo, bool debug);
void	eat(t_philo *philo);
void	thinking(t_philo *philo);
void	*monitor_dinner(void *data);
void	start_dinner(t_table *table);
#endif
