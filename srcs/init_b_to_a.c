/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:01:18 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/03 13:01:39 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_node;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		a_node = a;
		best_match = INT_MAX;
		while (a_node)
		{
			if (a_node->nbr > b->nbr && a_node->nbr < best_match)
			{
				best_match = a_node->nbr;
				target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (best_match == INT_MAX)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	push_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = len_b - b->index;
		if (b->target_node->above_median)
			b->push_price += b->target_node->index;
		else
			b->push_price += len_a - b->target_node->index;
		b = b->next;
	}
}

static void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest;

	if (stack == NULL)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < cheapest)
		{
			cheapest = stack->push_price;
			cheapest_node = stack;
		}
		stack->cheapest = false;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_b_to_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_for_b(a, b);
	push_price(a, b);
	set_cheapest(b);
}
