#include "../push_swap.h"

int stack_len(t_stack_node *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

t_stack_node	find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return ;
	while (head->next)
		head = head->next;
	return (head);
}