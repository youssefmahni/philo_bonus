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
		// safe_sem_unlink(ft_strjoin("sem_eat", i_to_a(i)));
		// safe_sem_unlink(ft_strjoin("sem_philo", i_to_a(i)));
	}
	sem_close(data->forks);
	sem_close(data->print_s);
	sem_close(data->dead_s);
	// sem_unlink("sem_fork");
	// sem_unlink("sem_print");
	// sem_unlink("sem_dead");
	free(data->philos);
}
