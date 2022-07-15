/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:10:01 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/15 14:02:22 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int    ft_atoi(char *s)
{
	int	i;
	int	stoi;

	i = 0;
	stoi = 0;
    if (!is_number(s))
    {
        printf("Error: %s is not a valid number\n", s);
        return (0);
    }
	while (s[i] >= '0' && s[i] <= '9')
	{
		stoi = stoi * 10 + (s[i] - '0');
		i++;
	}
	return (stoi);
}

int check_args(int ac, char **av, t_philo *philo)
{
    if (ac != 5 && ac != 6)
    {
        printf("Invalid number of arguments.\n");
        return (0);
    }
    philo->info->nb_philo = ft_atoi(av[1]);
    philo->info->time_to_die = ft_atoi(av[2]);
    philo->info->time_to_eat = ft_atoi(av[3]);
    philo->info->time_to_sleep = ft_atoi(av[4]);
    philo->info->nb_must_eat = -1;
    if (ac == 6)
        philo->info->nb_must_eat = ft_atoi(av[5]);
    if (philo->info->nb_philo <= 0 || philo->info->time_to_die <= 0 || philo->info->time_to_eat <= 0 ||
    philo->info->time_to_sleep <= 0 || (ac == 6 && philo->info->nb_must_eat <= 0))
    {
        printf("Invalid arguments.\n");
        return (0);
    }
    return (1);
}

void    philo_init(t_philo *philo)
{
    philo->info->nb_must_eat = 0;
    philo->info->nb_philo = 0;
    philo->info->time_to_die = 0;
    philo->info->time_to_eat = 0;
    philo->info->time_to_sleep = 0;
}
