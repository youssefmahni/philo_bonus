/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:39:39 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:39:40 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Error: malloc");
	return (ptr);
}

void safe_usleep(size_t to_sleep)
{
	size_t start_time;

	start_time = get_time();

	while (get_time() - start_time < to_sleep/ 1000)
		usleep(1000);
}

pid_t safe_fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		error_exit("Error: fork");
	return (pid);
}
