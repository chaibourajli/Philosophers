/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:48:40 by cbourajl          #+#    #+#             */
/*   Updated: 2022/07/14 14:19:33 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int test = 0;
pthread_mutex_t        mutex;

void    *philo()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        test++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int ac, char **av)
{
    pthread_t   th[100];
    int         i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 100; i++)
    {
        pthread_create(th + i, NULL, &philo, NULL);
        printf("philo %d is born\n", i);
    }
    for (i = 0; i < 100; i++){
        pthread_join(th[i], NULL);
        printf("philo %d is dead\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("%d\n", test);
}