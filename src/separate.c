#include "push_swap.h"

static	void	parse_values(t_sep **val)
{
	t_sep	*current;
	int		sum;

	current = *val;
	sum = (current->max - current->min) / current->div;
	current->mid_start = current->min + sum;
	current->mid_end = current->mid_start + sum;
}

static void	find_value(t_stack **stack, t_sep *val)
{
	t_stack	*current;

	current = *stack;
	if (current)
	{
		val->min = current->value;
		val->max = current->value;
		val->len = 1;
	}
	while (current && current->next)
	{
		current = current->next;
		if (current->value < val->min)
			val->min = current->value;
		else if (current->value > val->max)
			val->max = current->value;
		val->len++;
	}
	parse_values(&val);
}

static void	sort(t_stack **stack_a, t_stack **stack_b, t_sep *val)
{
	t_sep	val_b;

	if ((*stack_a)->value <= val->mid_start)
	{
		push(stack_a, stack_b, 'b');
		find_value(stack_b, &val_b);
		if (val_b.len > 2)
		{
			if ((*stack_a)->value > val->mid_end && (*stack_b)->next)
				rr(stack_b, stack_a);
			else
				rotate(stack_b, 'b');
		}
		else if (val_b.len == 2)
		{
			if ((*stack_a)->value == val_b.min)
				rotate(stack_b, 'b');
		}
	}
	else if ((*stack_a)->value >= val->mid_end)
		rotate(stack_a, 'a');
	else
		push(stack_a, stack_b, 'b');
}

void	separate(t_stack **stack_a, t_stack **stack_b, int divider)
{
	t_sep	val;

	val.div = divider;
	while (!is_sorted_ascending(stack_a) && (*stack_a))
	{
		find_value(stack_a, &val);
		if (val.len == 3)
			sort_three(stack_a);
		else if (val.len == 2)
			sort_two(stack_a);
		else
			sort(stack_a, stack_b, &val);
	}
	while (val.max > (*stack_a)->value && (*stack_b))
	{
		find_value(stack_b, &val);
		if (val.max > (*stack_a)->value)
			push(stack_a, stack_b, 'b');
	}
}
