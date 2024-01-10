/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:35:05 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:35:06 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		parse(av, &data);
		init(&data);
		simulate(&data);
		clean(&data);
	}
	else
		error_exit("Error: Wrong number of arguments");
	return (0);
}
