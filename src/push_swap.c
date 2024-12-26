#include "push_swap.h"

static int	divider(int *len)
{
	if (*len > 30 && *len < 251)
		return (4);
	else if (*len > 250 && *len < 750)
		return (9);
	else
		return (3);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc, argv, &stack_a);
	len = find_len(&stack_a);
	if (!is_sorted_ascending(&stack_a))
	{
		separate(&stack_a, &stack_b, divider(&len));
		sort_all(&stack_a, &stack_b);
	}
	while (stack_a)
		pop(&stack_a);
	while (stack_b)
		pop(&stack_b);
}
