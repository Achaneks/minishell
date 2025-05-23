NAME = minishell

SRC = src/main.c src/parser/check_couts.c src/parser/split.c src/parser/tokens.c src/utils/utils_parser.c src/utils/utils_token.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all