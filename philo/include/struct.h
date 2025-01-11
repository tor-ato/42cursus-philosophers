/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:10:53 by tkitahar          #+#    #+#             */
/*   Updated: 2025/01/05 19:53:14 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "philo.h"

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef long			t_millisecond;
typedef long			t_microsecond;
typedef long			t_second;

typedef enum e_error_code
{
	AC_ERROR,
	PARSE_ERROR,
	AC_SUCCESS,
	PARSE_SUCCESS,
}	t_error_code;

typedef enum e_init_code
{
	INIT_FALURE,
	INIT_SUCCESS,
}	t_init_code;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
	DEEP,
	SHALLOW,
}	t_philo_status;

typedef struct s_table
{
	long			philo_nbr;
	t_millisecond	time_to_die;
	t_millisecond	time_to_eat;
	t_millisecond	time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	long			nbr_running_threads;
	bool			end_simulation;
	bool			ready_threads;
	pthread_t		monitor;
	t_mtx			table_mutex;
	t_mtx			write_mutex;
	t_fork			*forks;
	t_philo			*philos;
}	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
	t_mtx		philo_mutex;
}	t_philo;

#endif
