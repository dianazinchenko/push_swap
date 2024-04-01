/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:16:50 by dzinchen          #+#    #+#             */
/*   Updated: 2024/03/29 15:18:31 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	//t_stack_node	*b;

	a = NULL;
	//b = NULL;
	if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		create_stack(&a, argv);
	}
	else
		create_stack(&a, argv + 1);
	ft_printf("Stack A:\n");
	print_stack(a);
	ft_printf("Swapped stack A:\n");
	sa(&a);
	print_stack(a);
	/*ft_printf("Stack len: %i\n", stack_len(a));
	rotate(&a);
	ft_printf("Stack A after rotate:\n");
	print_stack(a);*/
	return (0);
}