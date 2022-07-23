/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:58:06 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/23 13:47:43 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_passed(long long debut)
{
	long long		ecoule;
	struct timeval	time;

	gettimeofday(&time, NULL);
	ecoule = (time.tv_sec * 1000) + (time.tv_usec / 1000) - debut;
	return (ecoule);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + time.tv_usec / 1000);
}

void	ft_sleep(int time)
{
	long long	t;

	t = current_time();
	while (current_time() - t < time)
		usleep(100);
}
