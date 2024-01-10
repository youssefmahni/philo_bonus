CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
SRC = main_bonus.c init_bonus.c clean_bonus.c parse_bonus.c safe1_bonus.c safe2_bonus.c routine_bonus.c utils_bonus.c simulate_bonus.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean