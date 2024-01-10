#include "philo_bonus.h"

static inline bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static char	*format_number(char *str)
{
	int		i;
	char	*formated;

	i = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Error: Only positive numbers");
	if (!is_digit(*str))
		error_exit("Error: Not a number");
	formated = str;
	while (is_digit(*str++))
		i++;
	if (i > 10)
		error_exit("Error: Number is too big");
	return (formated);
}

static long	a_to_l(char *str)
{
	long	res;

	res = 0;
	str = format_number(str);
	while (is_digit(*str))
		res = res * 10 + (*str++ - '0');
	if (res > INT_MAX)
		error_exit("Error: Number is too big");
	return (res);
}

void	parse(char **av, t_data *data)
{
	data->philos_num = a_to_l(av[1]);
	data->time_to_die = a_to_l(av[2]);
	data->time_to_eat = a_to_l(av[3]);
	data->time_to_sleep = a_to_l(av[4]);
	if (av[5])
		data->must_eat = a_to_l(av[5]);
	else
		data->must_eat = -1;
}
