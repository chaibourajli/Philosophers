/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:48:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/15 14:24:49 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_thread()
{
    void    *ret;
    ret = NULL;
    printf("a philo is born\n");
    return (ret);
}

int main(int ac, char **av)
{
    t_philo *philo;
    int     i;

    i = 1;
    philo = malloc(sizeof(t_philo));
    philo_init(philo);
    if (!check_args(ac, av, philo))
        return (0);
    while (i <= philo->info->nb_philo)
    {
        pthread_create(&philo->philo, NULL, philo_thread, NULL);
        i++;
    }
    i = 1;
    while (i <= philo->info->nb_philo)
    {
        pthread_join(philo->philo, NULL);
        i++;
    }
}