NAME = minishell

<<<<<<< HEAD
SRC = src/main.c src/ft_split.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
=======
SRC = src/main.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = -lreadline
>>>>>>> f4cd3977161ea9e23c4a409204ccd8fbd4bf528c

all: $(NAME)

$(NAME): $(OBJ)
<<<<<<< HEAD
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline
=======
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
>>>>>>> f4cd3977161ea9e23c4a409204ccd8fbd4bf528c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all