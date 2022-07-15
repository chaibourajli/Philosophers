/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:53:37 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/15 14:12:58 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H 
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>

typedef struct s_attr{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
}    t_attr;

typedef struct s_philo{
    t_attr *info;
    pthread_t philo;
    pthread_mutex_t *fork;
    struct s_philo *left;
}   t_philo;


int     ft_atoi(char *s);
int     is_number(char *str);
int     check_args(int ac, char **av, t_philo *philo);
void    philo_init(t_philo *philo);

#endif