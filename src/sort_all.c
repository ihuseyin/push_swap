#include "push_swap.h"

static	void	find_value(t_stack **stack, t_value *val)
{
	t_stack	*current;

	current = *stack;
	if (current)
	{
		val->max = current->value;
		val->len = 1;
		val->max_index = 1;
	}
	while (current && current->next)
	{
		current = current->next;
		val->len++;
		if (current->value > val->max)
		{
			val->max = current->value;
			val->max_index = val->len;
		}
	}
}

static void	check(t_stack **stack_a, t_stack **stack_b, t_check *val)
{
	t_value	new_val;
	int		min;

	min = 0;
	find_value(stack_b, &new_val);
	if (val->index == 3)
		min = val->second;
	else if (val->index == 2)
		min = val->first;
	else if (val->index == 1)
		min = val->min_val;
	if (min > new_val.max || !*stack_b)
	{
		if (new_val.max_index > new_val.len / 2 && new_val.len > 1 && *stack_b)
			rrr(stack_a, stack_b);
		else
			reverse_rotate(stack_a, 'a');
		if (val->index == 3)
		{
			val->index--;
			check(stack_a, stack_b, val);
		}
		else
			val->check = false;
	}
}

static void	check_five(t_stack **stack_a, t_stack **stack_b, t_check *val)
{
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			ss(stack_a, stack_b);
		else
			swap(stack_a, 'a');
	}
	val->first = (*stack_a)->value;
	rr(stack_a, stack_b);
	val->second = (*stack_a)->value;
	rr(stack_a, stack_b);
	val->index = 3;
	val->check = true;
}

static void	check_three(t_stack **stack_a, t_stack **stack_b, t_check *val)
{
	val->min_val = (*stack_b)->value;
	push(stack_a, stack_b, 'a');
	rr(stack_a, stack_b);
	val->index = 1;
	val->check = true;
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	t_value	len;
	t_check	val;

	val.check = false;
	while (*stack_b)
	{
		find_value(stack_b, &len);
		if ((*stack_b)->value == len.max)
			push(stack_a, stack_b, 'a');
		else if (len.max_index == 5 && !val.check)
			check_five(stack_a, stack_b, &val);
		else if (len.max_index == 3 && !val.check)
			check_three(stack_a, stack_b, &val);
		else if (len.max_index == 2)
			swap(stack_b, 'b');
		else if ((len.len / 2) > len.max_index)
			rotate(stack_b, 'b');
		else
			reverse_rotate(stack_b, 'b');
		if (val.check)
			check(stack_a, stack_b, &val);
	}
}
