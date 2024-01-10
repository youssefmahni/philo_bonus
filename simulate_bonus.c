/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:39:44 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:39:45 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*eat_counter(void *arg)
{
	t_data	*data;
	int		i;
	int		times;

	data = (t_data *)arg;
	times = 0;
	while (times < data->must_eat)
	{
		i = 0;
		while (i < data->philos_num)
			sem_wait(data->philos[i++].eat_s);
		times++;
	}
	sem_post(data->dead_s);
	return (NULL);
}

static void	start_counter(t_data *data)
{
	pthread_t	th;

	if (data->must_eat >= 0)
	{
		safe_thread_create(&th, eat_counter, (void *)data);
		safe_thread_detach(th);
	}
}

void	simulate(t_data *data)
{
	int	i;

	i = -1;
	start_counter(data);
	data->start_time = get_time();
	while (++i < data->philos_num)
	{
		data->philos[i].pid = safe_fork();
		if (data->philos[i].pid == 0)
			routine(&data->philos[i]);
		safe_usleep(100);
	}
	sem_wait(data->dead_s);
}
