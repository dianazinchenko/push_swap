/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:13:34 by dzinchen          #+#    #+#             */
/*   Updated: 2024/04/03 12:59:30 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	create_stack(t_stack_node **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (ft_strlen(argv[i]) > 11 || nbr < INT_MIN || nbr > INT_MAX)
			error_free(a, argv, argc_2);
		if (repetition_error(*a, (int)nbr))
			error_free(a, argv, argc_2);
		if (syntax_error(argv[i]))
			error_free(a, argv, argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (argc_2)
		free_matrix(argv);
}
