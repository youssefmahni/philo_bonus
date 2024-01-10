#include "philo_bonus.h"

static int	init_philos(t_data *data)
{
	int		i;
	char	*sem_name;

	data->philos = safe_malloc(data->philos_num * sizeof(t_philo));
	i = -1;
	while (++i < data->philos_num)
	{
		data->philos[i].position = i + 1;
		data->philos[i].is_eating = 0;
		data->philos[i].meals_count = 0;
		sem_name = ft_strjoin("sem_eat", i_to_a(i));
		data->philos[i].eat_s = safe_sem_open(sem_name, 0, 1);
		sem_name = ft_strjoin("sem_philo", i_to_a(i));
		data->philos[i].philo_s = safe_sem_open(sem_name, 1, 1);
		data->philos[i].state = data;
	}
	return (0);
}

static void	init_semaphores(t_data *data)
{
	data->print_s = safe_sem_open("sem_print", 1, 0);
	data->dead_s = safe_sem_open("sem_dead", 0, 0);
	data->forks = safe_sem_open("sem_fork", data->philos_num, 0);
}

void	init(t_data *data)
{
	init_philos(data);
	init_semaphores(data);
}
