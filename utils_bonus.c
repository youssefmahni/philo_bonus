/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:38:21 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:38:49 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_exit(char *err)
{
	printf("%s", err);
	exit(EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct timeval	tv;
	long			time;

	if (gettimeofday(&tv, NULL))
		error_exit("Error: gettimeofday");
	time = tv.tv_sec * 1e3 + tv.tv_usec / 1e3;
	return (time);
}

char	*i_to_a(int n)
{
	int		i;
	int		len;
	char	*str;

	i = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (i)
	{
		i /= 10;
		len++;
	}
	str = safe_malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = safe_malloc((i + j + 1) * sizeof(char));
	str[i + j] = '\0';
	while (j--)
		str[i + j] = s2[j];
	while (i--)
		str[i] = s1[i];
	free(s2);
	return (str);
}

void	print_status(t_philo *philo, char *status)
{
	size_t	time;

	sem_wait(philo->state->print_s);
	time = get_time() - philo->state->start_time;
	printf("%ld %d %s\n", time, philo->position, status);
	sem_post(philo->state->print_s);
}
