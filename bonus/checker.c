#include "checker.h"
#include <unistd.h>

void	free_all(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
		pop(stack_a);
	while (*stack_b)
		pop(stack_b);
}

static int	is_sorted_ascending(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*next;

	if (!*stack)
		return (0);
	prev = *stack;
	while (prev && prev->next)
	{
		next = prev->next;
		if (prev->value > next->value)
			return (0);
		prev = prev->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc, argv, &stack_a);
	read_input(&stack_a, &stack_b);
	if (is_sorted_ascending(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&stack_a, &stack_b);
}
