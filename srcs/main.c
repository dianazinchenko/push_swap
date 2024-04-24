/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:16:50 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/24 13:35:43 by dzinchen         ###   ########.fr       */
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
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	ft_printf("Stack A:\n");
	print_stack(a);
	ft_printf("Stack B:\n");
	print_stack(b);
	printf("%ld\n", LONG_MAX);
	printf("%i", INT_MAX);	
	
	/*ft_printf("Stack A:\n");
	print_stack(a);
	t_stack_node	*biggest = find_biggest_node(a);
	ft_printf("\nbiggest: %i\n", biggest->nbr);
	ft_printf("Sorted 3 numbers:\n");
	sort_three(&a);
	print_stack(a);
	ft_printf("Stack B:\n");
	print_stack(b);*/
	
	return (0);
}
