#include "push_swap.h"
#include <stdlib.h>

int	pop(t_stack **stack)
{
	t_stack	*top;
	int		value;

	top = *stack;
	value = top->value;
	*stack = (*stack)->next;
	free(top);
	return (value);
}

void	new_node(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		while (*stack)
			pop(stack);
		exit(-1);
	}
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}
