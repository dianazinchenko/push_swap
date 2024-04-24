/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:02:02 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/03 13:02:07 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	prep_for_push(t_stack_node **stack, t_stack_node *target_node, char c)
{
	while (*stack != target_node)
	{
		if (c == 'a')
		{
			if (target_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c == 'b')
		{
			if (target_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(b, a);
}

static void	smallest_to_top(t_stack_node **a)
{
	while ((*a)->nbr != find_smallest_node(*a)->nbr)
	{
		if (find_smallest_node(*a)->above_median == true)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int		len_a;
	int		i;

	len_a = stack_len(*a);
	i = 0;
	while (i++ < 2)
	{
		if (len_a-- > 3 && !sorted_stack(*a))
			pb(a, b);
	}
	while (len_a-- > 3 && !sorted_stack(*a))
	{
		init_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	smallest_to_top(a);
}
