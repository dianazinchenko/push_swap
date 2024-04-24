/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:00:45 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/03 13:00:49 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*find_smallest_node(t_stack_node *stack)
{
	t_stack_node	*smallest;

	if (stack == NULL)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->nbr < smallest->nbr)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (stack == NULL)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
