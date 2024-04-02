/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:36:43 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/02 11:36:52 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	temp = last_node;
	last_node = last_node->prev;
	last_node->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}