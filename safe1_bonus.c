#include "philo_bonus.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit("Error: malloc");
	return (ptr);
}

void safe_usleep(long to_sleep)
{
	long start_time;

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
