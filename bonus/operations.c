#include "checker.h"

void	swap(t_stack **stack)
{
	t_stack	*current;
	int		temp;

	current = *stack;
	if (current && current->next)
	{
		temp = current->value;
		current->value = current->next->value;
		current->next->value = temp;
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (c == 'a')
	{
		if (*stack_b)
			new_node(stack_a, pop(stack_b));
	}
	else if (c == 'b')
	{
		if (*stack_a)
			new_node(stack_b, pop(stack_a));
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}
