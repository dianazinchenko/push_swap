#include "../push_swap.h"

void	print_stack(t_stack_node *stack) 
{
	t_stack_node *temp = stack;

	while (temp != NULL) 
	{
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}
