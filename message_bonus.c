#include "philo_bonus.h"

static char	*get_message(t_status status)
{
	if (status == TAKING_FORK)
		return ("has taken a fork");
	else if (status == EATING)
		return ("is eating");
	else if (status == SLEEPING)
		return ("is sleeping");
	else if (status == THINKING)
		return ("is thinking");
	else if (status == DEAD)
		return ("died");
}

void	print_status(t_philo *philo, t_status status)
{
	size_t	time;
	char	*msg;

	sem_wait(philo->state->print_s);
	msg = get_message(status);
	time = get_time() - philo->state->start_time;
	printf("%ld %d %s\n", time, philo->position, msg);
	if (status != DEAD)
		sem_post(philo->state->print_s);
}
