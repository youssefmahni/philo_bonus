/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:29:48 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:29:49 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_num)
	{
		kill(data->philos[i].pid, SIGKILL);
		sem_close(data->philos[i].eat_s);
		sem_close(data->philos[i].philo_s);
	}
	sem_close(data->forks);
	sem_close(data->print_s);
	sem_close(data->dead_s);
	free(data->philos);
}
