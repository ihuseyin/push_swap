#include "push_swap.h"
#include <unistd.h>

void	swap(t_stack **stack, int c)
{
	t_stack	*current;
	int		temp;

	current = *stack;
	if (current && current->next)
	{
		temp = current->value;
		current->value = current->next->value;
		current->next->value = temp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	push(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (c == 'a')
	{
		if (*stack_b)
		{
			new_node(stack_a, pop(stack_b));
			write(1, "pa\n", 3);
		}
	}
	else if (c == 'b')
	{
		if (*stack_a)
		{
			new_node(stack_b, pop(stack_a));
			write(1, "pb\n", 3);
		}
	}
}

void	rotate(t_stack **stack, int c)
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
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_stack **stack, int c)
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
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}
