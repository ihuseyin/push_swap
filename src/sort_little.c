#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	first;
	int	mid;
	int	last;

	while (!is_sorted_ascending(stack))
	{
		first = (*stack)->value;
		mid = (*stack)->next->value;
		last = (*stack)->next->next->value;
		if (first > mid && mid < last && first < last)
			swap(stack, 'a');
		else if (first < mid && mid > last && (first > last || first < last))
			reverse_rotate(stack, 'a');
		else if (first > mid && (mid < last || mid > last) && first > last)
			rotate(stack, 'a');
	}
}

void	sort_two(t_stack **stack)
{
	int	first;
	int	second;

	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first > second)
		swap(stack, 'a');
}