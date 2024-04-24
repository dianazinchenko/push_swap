/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:02:42 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/02 15:27:41 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_price;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}					t_stack_node;

/* Utils */
int				stack_len(t_stack_node *stack);
long			ft_atol(char *str);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_biggest_node(t_stack_node *head);
bool			sorted_stack(t_stack_node *stack);
t_stack_node	*find_smallest_node(t_stack_node *head);
void			current_index(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);

/* Input Error */
int				syntax_error(char *str);
int				repetition_error(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **a);

/* Create Stack */
void			append_node(t_stack_node **stack, int nbr);
void			create_stack(t_stack_node **a, char **argv);

/* Swap Operations */
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

/* Rotate Operations */
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

/* Reverse Rotate Operations */
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

/* Push Operations */
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

/* Sort Three */
void			sort_three(t_stack_node **a);

/* Init A to B */
void			init_a_to_b(t_stack_node *a, t_stack_node *b);

/* Init B to A */
void			init_b_to_a(t_stack_node *a, t_stack_node *b);

/* Sort Stack */
void			sort_stack(t_stack_node **a, t_stack_node **b);

/* TESTING */
void			print_stack(t_stack_node *stack);

#endif
