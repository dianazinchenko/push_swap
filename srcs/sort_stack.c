/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:02:02 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/26 10:53:42 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	prep_for_push(t_stack_node **stack,
		t_stack_node *target_node, char c)
{
	while (*stack != target_node)
	{
		if (c == 'a')
		{
			if (target_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (c == 'b')
		{
			if (target_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	pa(b, a, false);
}

static void	smallest_to_top(t_stack_node **a)
{
	while ((*a)->nbr != find_smallest_node(*a)->nbr)
	{
		if (find_smallest_node(*a)->above_median == true)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3 && !sorted_stack(*a))
		pb(a, b, false);
	sort_three(a);
	while (*b)
	{
		init_b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	smallest_to_top(a);
}
