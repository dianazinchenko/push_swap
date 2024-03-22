NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = lib/libft/libft.a

LIBFT_DIR = lib/libft

SRCS = srcs/utils.c srcs/rotate_operations.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all