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
