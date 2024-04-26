/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:16:50 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/26 10:52:30 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		create_stack(&a, argv);
	}
	else
		create_stack(&a, argv + 1);
	if (!sorted_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	/*printf("Stack a:\n");
	print_stack(a);
	printf("Stack b:\n");
	print_stack(b);*/

	// test operations
	//sa(&a, false);
	//sb(&b, false);
	//ss(&a, &b, false);
	//pa(&b, &a, false);
	//pb(&a, &b, false);
	//ra(&a, false);
	//rb(&b, false);
	//rr(&a, &b, false);
	//rra(&a, false);
	//rrb(&b, false);
	//rrr(&a, &b, false);

/*	printf("\nStack a after:\n");
	print_stack(a);
	printf("Stack b after:\n");
	print_stack(b);*/
	free_stack(&a);
	
	return (0);
}
