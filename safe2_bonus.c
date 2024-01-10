/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:39:41 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:39:42 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*safe_sem_open(char *name, int value, bool free_name)
{
	sem_t	*sem;

	sem_unlink(name); // it's ok if it fails
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem == SEM_FAILED)
		error_exit("sem_open failed");
	if (free_name)
		free(name);
	return (sem);
}

void	safe_sem_close(sem_t *sem)
{
	if (sem_close(sem))
		error_exit("sem_close failed");
}

void	safe_thread_create(pthread_t *thread, void *(*func)(void *), void *arg)
{
	if (pthread_create(thread, NULL, func, arg))
		error_exit("Error: pthread_create");
}

void	safe_thread_detach(pthread_t thread)
{
	if (pthread_detach(thread))
		error_exit("Error: pthread_detach");
}
