#include "../push_swap.h"

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] >= '0' || str[i] <= '9'))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	repetition_error(t_stack_node *stack, int nbr)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL; // to avoid undefined behavior
}

void	error_free(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}