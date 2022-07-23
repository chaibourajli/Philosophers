/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:38:13 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/23 12:20:30 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo	*philo)
{
	t_philo	*right_fork;

	right_fork = NULL;
	if (philo->next != NULL)
		right_fork = philo->next;
	else if (philo->next == NULL)
		right_fork = philo->info->first;
	pthread_mutex_lock(&philo->fork);
	print_status(philo, 1, "has taken a fork\n");
	pthread_mutex_lock(&right_fork->fork);
	print_status(philo, 1, "has taken a fork\n");
	philo->last_meal = current_time();
	print_status(philo, 1, "is eating\n");
	ft_sleep(philo->info->time_to_eat);
	philo->eaten++;
	if (philo->eaten == philo->info->nb_must_eat)
		philo->info->check_meals++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&right_fork->fork);
}

void	sleeping(t_philo	*philo)
{
	print_status(philo, 1, "is sleeping\n");
	ft_sleep(philo->info->time_to_sleep);
}

void	thinking(t_philo	*philo)
{
	print_status(philo, 1, "is thinking\n");
}

void	init_philo(t_attr *info, t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	tmp = NULL;
	info->begin_time = current_time();
	info->check_meals = 0;
	while (i <= info->nb_philo)
	{
		tmp = new_philo(i, info);
		add_next(&philo, tmp);
		i++;
	}
	i = 0;
	info->first = philo;
	tmp = philo;
	while (i < info->nb_philo)
	{
		pthread_create(&tmp->thread, NULL, routine, tmp);
		tmp = tmp->next;
		i++;
	}
	tmp = philo;
	check_death(philo);
}

void	*routine(void	*philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (philo->id % 2 == 0)
		usleep (500);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}