#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "lib/libft/libft.h"

typedef struct s_stack_node
{
    int         nbr;
    int         current;
    int         push_price;
    bool	    above_median;
    bool 		cheapest;
    struct s_stack_node	*target;
    struct s_stack_node	*next;
    struct s_stack_node	*prev;
}				t_stack_node;

/* Utils */
int	stack_len(t_stack_node *stack);
long	ft_atol(char *str);
t_stack_node	find_last_node(t_stack_node *head);

/* Rotate Operations */
int stack_len(t_stack_node *stack);

#endif