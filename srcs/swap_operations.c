#include "../push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*temp;

	if (!(*head) || !((*head)->next))
		return ;
	temp = (*head)->next->next;
	if (temp)
		temp->prev = (*head);
	(*head) = (*head)->next;
	(*head)->next = (*head)->prev;
	(*head)->next->next = temp;
	(*head)->next->prev = (*head);
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
}

void	sb(t_stack_node **b)
{
	swap(b);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}