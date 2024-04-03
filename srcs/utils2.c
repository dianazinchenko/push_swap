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

t_stack_node	*find_smallest_node(t_stack_node *head)
{
	t_stack_node	*smallest;

	if (head == NULL)
		return (NULL);
	smallest = head;
	while (head)
	{
		if (head->nbr < smallest->nbr)
			smallest = head;
		head = head->next;
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
