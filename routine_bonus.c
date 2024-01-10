#include "philo_bonus.h"

static void	*is_alive(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->philo_s);
		if (get_time() > philo->last_eat + philo->state->time_to_die)
		{
			print_status(philo, DEAD);
			sem_post(philo->philo_s);
			sem_post(philo->state->dead_s);
			return (NULL);
		}
		else
			sem_post(philo->philo_s);
		safe_usleep(1000);
	}
	return (NULL);
}

static void	get_forks(t_philo *philo)
{
	sem_wait(philo->state->forks);
	print_status(philo, TAKING_FORK);
	sem_wait(philo->state->forks);
	print_status(philo, TAKING_FORK);
}

static void	put_forks(t_philo *philo)
{
	sem_post(philo->state->forks);
	sem_post(philo->state->forks);
	print_status(philo, SLEEPING);
	safe_usleep(philo->state->time_to_sleep * 1000);
}

static void	eat(t_philo *philo)
{
	sem_wait(philo->philo_s);
	philo->last_eat = get_time();
	print_status(philo, EATING);
	safe_usleep(philo->state->time_to_eat * 1000);
	philo->meals_count++;
	sem_post(philo->philo_s);
	sem_post(philo->eat_s);
}

void	routine(t_philo *philo)
{
	pthread_t th;

	philo->last_eat = get_time();
	safe_thread_create(&th, is_alive, (void *)philo);
	safe_thread_detach(th);
	while (1)
	{
		get_forks(philo);
		eat(philo);
		put_forks(philo);
		print_status(philo, THINKING);
	}
	exit(0);
}