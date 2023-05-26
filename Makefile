NAME=push_swap

SRCS=main.c control.c rules.c index.c radix.c mini_sort.c

OBJS= $(SRCS:.c=.o)

LIBFT_DIR = libft

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re