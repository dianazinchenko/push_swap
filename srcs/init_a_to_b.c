/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:59:56 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/03 13:00:34 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_for_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*b_node;
	t_stack_node	*target_node;
	long			best_match;

	while (a)
	{
		b_node = b;
		best_match = LONG_MIN;
		while (b_node)
		{
			if (b_node->nbr < a->nbr && b_node->nbr > best_match)
			{
				best_match = b_node->nbr;
				target_node = b_node;
			}
			b_node = b_node->next;
		}
	
		if (best_match == LONG_MIN)
			a->target_node = find_smallest_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	push_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_price = a->index;
		if (!(a->above_median))
			a->push_price = len_a - a->index;
		if (a->target_node->above_median)
			a->push_price += a->target_node->index;
		else
			a->push_price += len_b - a->target_node->index;
		a = a->next;
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
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_a_to_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_for_a(a, b);
	push_price(a, b);
	set_cheapest(a);
}
