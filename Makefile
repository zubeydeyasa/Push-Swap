NAME=push_swap

SRCS=main.c control.c rules.c index.c radix.c mini_sort.c

OBJS= $(SRCS:.c=.o)

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re