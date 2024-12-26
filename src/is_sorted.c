#include "push_swap.h"

int	find_len(t_stack **stack)
{
	t_stack	*current;
	int		len;

	current = *stack;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	is_sorted_ascending(t_stack **stack)
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
