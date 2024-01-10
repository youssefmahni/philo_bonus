/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:39:34 by ymahni            #+#    #+#             */
/*   Updated: 2024/01/10 22:39:35 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>    
# include <limits.h>   
# include <pthread.h>  
# include <semaphore.h> 
# include <signal.h> 
# include <stdbool.h>
# include <stdio.h>   
# include <stdlib.h>   
# include <sys/time.h> 
# include <unistd.h>  

struct s_data;

typedef struct s_philo
{
	pid_t pid;         
	int position;        
	int meals_count; 
	size_t last_eat;     
	struct s_data *state;
	sem_t *philo_s;
	sem_t *eat_s;
}			t_philo;

typedef struct s_data
{
	int philos_num;  
	size_t start_time; 
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int must_eat;    
	t_philo *philos; 
	sem_t *forks;    
	sem_t *print_s;  
	sem_t *dead_s;   
}			t_data;

# define TAKING_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "died"

// utils.c
void		error_exit(char *err);
size_t		get_time(void);
char		*i_to_a(int n);
char		*ft_strjoin(char *s1, char *s2);

// safe.c
void		*safe_malloc(size_t size);
void		safe_usleep(size_t to_sleep);
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
void		print_status(t_philo *philo, char *status);

//routine_bonus.c
void		simulate(t_data *data);
void	routine(t_philo *philo);
#endif