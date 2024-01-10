#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>     // used for O_CREAT and O_EXCL flags
# include <limits.h>    // used for INT_MAX
# include <pthread.h>   // used for pthread_create and pthread_detach
# include <semaphore.h> // used for sem_open, sem_wait and sem_post
# include <signal.h>    // used for kill
# include <stdbool.h>
# include <stdio.h>    // used for printf
# include <stdlib.h>   // used for malloc and free
# include <sys/time.h> // used for gettimeofday
# include <unistd.h>   // used for usleep

struct s_data;

typedef struct s_philo
{
	pid_t pid;            // process id
	int position;         // position of the philosopher
	int is_eating;        // 1 if the philosopher is eating, 0 otherwise
	int meals_count;      // number of times the philosopher has eaten
	size_t limit;         // time limit to die
	size_t last_eat;      // time of the last meal
	struct s_data *state; // pointer to the state
	sem_t *philo_s;       // semaphore for the philosopher
	sem_t *eat_s;         // semaphore for the number of meals
}			t_philo;

typedef struct s_data
{
	int philos_num;    // number of philosophers
	size_t start_time; // time when the simulation started
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int must_eat;    // maximum number of meals
	t_philo *philos; // array of philosophers
	sem_t *forks;    // semaphore for the forks
	sem_t *print_s;  // semaphore for the print
	sem_t *dead_s;   // semaphore for the death
}			t_data;

typedef enum e_status
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}			t_status;

// utils.c
void		error_exit(char *err);
long		get_time(void);
char		*i_to_a(int n);
char		*ft_strjoin(char *s1, char *s2);

// safe.c
void		*safe_malloc(size_t size);
void		safe_usleep(long to_sleep);
void		safe_thread_create(pthread_t *thread, void *(*func)(void *),
				void *arg);
void		safe_thread_detach(pthread_t thread);

//safe2.c
sem_t		*safe_sem_open(char *name, int value, bool free_name);
void		safe_sem_close(sem_t *sem);
pid_t		safe_fork(void);

//parse.c
void		parse(char **av, t_data *data);

//init.c
void		init(t_data *data);

//clean_bonus.c
void		clean(t_data *data);

//message_bonus.c
void		print_status(t_philo *philo, t_status status);

//routine_bonus.c
void		simulate(t_data *data);
void	routine(t_philo *philo);
#endif