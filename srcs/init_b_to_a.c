#include "../push_swap.h"

static void	set_target_for_b(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*a_node;
	t_stack_node	*target_node;
	long			best_match;

	if (a == NULL || b == NULL)
		return ;
	while (b)
	{
		a_node = a;
		best_match = LONG_MAX;
		while (a_node)
		{
			if (a_node->nbr > b->nbr && a_node->nbr < best_match)
			{
				best_match = a_node->nbr;
				target_node = a_node;
			}
			a_node = a_node->next;
		}
	}
	if (best_match == LONG_MAX)
			b->target_node = find_biggest_node(a);
		else
			b->target_node = target_node;
	b = b->next;
}

void	init_b_to_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_for_b(b, a);
}