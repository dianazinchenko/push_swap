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

int	repetition_error(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}