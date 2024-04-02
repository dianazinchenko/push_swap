/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:02:42 by dzinchen          #+#    #+#             */
/*   Updated: 2024/03/29 15:27:06 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int				nbr;
	int				current;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

/* Utils */
int		stack_len(t_stack_node *stack);
long		ft_atol(char *str);
t_stack_node	*find_last_node(t_stack_node *head);

/* Input Error */
int		syntax_error(char *str);
int		repetition_error(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a);

/* Create Stack */
void	append_node(t_stack_node **stack, int nbr);
void	create_stack(t_stack_node **a, char **argv);

/* Swap Operations */
void	swap(t_stack_node **head);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

/* Rotate Operations */
void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

/* Reverse Rotate Operations */
void	reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

/* Sort Three */
//todo: void    sort_three(t_stack_node **stack);

/* TESTING */
void	print_stack(t_stack_node *stack);

#endif
