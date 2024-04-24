NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

LIBFT_DIR = libft

SRCS = srcs/utils.c srcs/utils2.c srcs/create_stack.c srcs/input_error.c srcs/rotate_operations.c srcs/testing.c srcs/main.c \
srcs/swap_operations.c srcs/reverse_rotate_operations.c srcs/rotate_operations2.c srcs/push_operations.c srcs/sort_three.c srcs/init_a_to_b.c \
srcs/init_b_to_a.c srcs/sort_stack.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all