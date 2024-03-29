#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

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
t_stack_node	*find_last_node(t_stack_node *head);

/* Input Error */
int	syntax_error(char *str);
int	repetition_error(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a);

/* Create Stack */
void	append_node(t_stack_node **stack, int nbr);
void	create_stack(t_stack_node **a, char **argv);

/* Sort Three */
//todo: void    sort_three(t_stack_node **a);

/* Rotate Operations */
//todo: void	rotate(t_stack_node **stack);

/* TESTING */
void print_stack(t_stack_node *stack);

/* Split */
// todo:

#endif