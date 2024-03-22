void	create_stack(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || ft_strlen(argv[i]) > 11)
			// TODO: error handle
		if (repetition_error(*a, (int)nbr))
			// TODO: error handle
		append_node(a, (int)nbr);
	}
}