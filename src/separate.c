#include "push_swap.h"

static	void	parse_values(t_sep **val)
{
	t_sep	*current;
	int		sum;

	current = *val;
	current->div = ft_divider(current->len);
	sum = (current->max - current->min) / current->div;
	current->mid_start = current->min + sum;
	current->mid_end = current->mid_start + sum;
}

static void	find_value(t_stack **stack, t_sep *val, bool check)
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
	if (val->len > 3 && check)
		parse_values(&val);
}

static void	sort(t_stack **stack_a, t_stack **stack_b, t_sep *val)
{
	if ((*stack_a)->value <= val->mid_start && (*stack_b))
	{
		push(stack_a, stack_b, 'b');
		if ((*stack_a)->value > val->mid_end && (*stack_b)->next->next)
			rr(stack_b, stack_a);
		else if ((*stack_b)->next->next)
			rotate(stack_b, 'b');
	}
	else if ((*stack_a)->value >= val->mid_end)
		rotate(stack_a, 'a');
	else
		push(stack_a, stack_b, 'b');
}

void	separate(t_stack **stack_a, t_stack **stack_b)
{
	t_sep	val;

	while (!is_sorted_ascending(stack_a) && (*stack_a))
	{
		find_value(stack_a, &val, true);
		if (val.len > 3)
			sort(stack_a, stack_b, &val);
		else if (val.len == 3)
			sort_three(stack_a);
		else if (val.len == 2)
			sort_two(stack_a);
	}
	while (val.max > (*stack_a)->value && (*stack_b))
	{
		find_value(stack_b, &val, false);
		if (val.max > (*stack_a)->value)
			push(stack_a, stack_b, 'b');
		if (!*stack_a)
			break ;
	}
}
