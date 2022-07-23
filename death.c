/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:59:57 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/23 13:19:28 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	while (1)
	{
		if (current_time() - philo->last_meal >= philo->info->time_to_die)
		{
			print_status(philo, 0, "is dead\n");
			break ;
		}
		else if (philo->info->check_meals == philo->info->nb_philo)
		{
			print_status(philo, 0, "finish\n");
			break ;
		}
		else if (philo->next == NULL)
			philo = philo->info->first;
		else
			philo = philo->next;
	}
}

void	print_status(t_philo *philo, int n, char *str)
{
	long long	time;

	pthread_mutex_lock (&philo->info->mutex);
	time = current_time() - philo->info->begin_time;
	printf ("%lld %d %s", time, philo->id, str);
	if (n)
		pthread_mutex_unlock(&philo->info->mutex);
}
