NAME = philo

SRC = main.c \
	  routine.c \
	  utils.c \
	  more_utils.c \
	  ft_ft.c\
	  ft_error.c

all: $(NAME)

$(NAME):
	gcc $(SRC) -pthread -Wall -Werror -Wextra  -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: fclean all re clean
