/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:48:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/23 12:23:07 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_attr	info;
	int		i;

	philo = NULL;
	i = 1;
	while (av[i])
	{
		if (!ft_atoi(av[i]))
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	if (!check_args (ac, av, &info))
		return (1);
	init_philo (&info, philo);
}
