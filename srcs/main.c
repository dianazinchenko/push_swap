#include "../push_swap.h"

int     main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
    {
        ft_printf("Error\n");
        return (1);
		// TODO: handle error
    }
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    create_stack(&a, argv + 1);
}
