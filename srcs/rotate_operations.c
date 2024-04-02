/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:18:50 by dzinchen          #+#    #+#             */
/*   Updated: 2024/03/29 15:18:53 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node = find_last_node(*stack);
	last_node->next = temp;
	temp->prev = last_node;
	temp->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
}

void	rb(t_stack_node **b)
{
	rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}