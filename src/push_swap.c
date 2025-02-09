#include "push_swap.h"
#include <stdlib.h>

int	ft_divider(int len)
{
	if (len > 30 && len <= 100)
		return (6);
	else if (len > 100 && len <= 150)
		return (8);
	else if (len > 150 && len <= 200)
		return (9);
	else if (len > 200 && len <= 300)
		return (10);
	else if (len > 300 && len <= 400)
		return (12);
	else if (len > 400 && len <= 700)
		return (15);
	else
		return (4);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc - 1, argv, &stack_a);
	if (!is_sorted_ascending(&stack_a))
	{
		separate(&stack_a, &stack_b);
		sort_all(&stack_a, &stack_b);
	}
	while (stack_a)
		pop(&stack_a);
	while (stack_b)
		pop(&stack_b);
	return (0);
}
