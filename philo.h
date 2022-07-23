/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:53:37 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/23 12:25:53 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_attr{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				finished;
	int				dead;
	int				check_meals;
	long long		begin_time;
	pthread_mutex_t	mutex;
	struct s_philo	*first;
}	t_attr;

typedef struct s_philo{
	struct s_attr	*info;
	int				id;
	int				eaten;
	long long		last_meal;
	pthread_mutex_t	fork;
	pthread_t		thread;
	struct s_philo	*next;
}	t_philo;

int			ft_atoi(char *s);
int			is_number(char *str);
int			check_args(int ac, char **av, t_attr *info);
void		ft_sleep(int time);
void		add_next(t_philo **philo, t_philo *new);
void		eating(t_philo	*philo);
void		sleeping(t_philo	*philo);
void		thinking(t_philo	*philo);
void		init_philo(t_attr *info, t_philo *philo);
void		print_status(t_philo *philo, int status, char *str);
void		check_death(t_philo *philo);
void		*routine(void *philos);
long long	time_passed(long long debut);
long long	current_time(void);
t_philo		*new_philo(int i, t_attr *info);

#endif
