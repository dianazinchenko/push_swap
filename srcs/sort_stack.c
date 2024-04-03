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

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int		len;
	int		i;

	len = stack_len(*a);
	i = 0;
	while (i++ < 2)
	{
		if (len-- > 3 && !sorted_stack(*a))
			pb(a, b);
	}
	while (len-- > 3 && !sorted_stack(*a))
	{
		// todo: move nodes from a to b
	}
	sort_three(a);
	while (*b)
	{
		// tood: move nodes from b to a
	}
	//move min to the top
}
