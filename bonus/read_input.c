#include "checker.h"
#include <unistd.h>

static int	strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	double_ops(t_stack **stack_a, t_stack **stack_b, char *value)
{
	if (!strcmp(value, "rra\n"))
		reverse_rotate(stack_a);
	else if (!strcmp(value, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!strcmp(value, "ss\n"))
		ss(stack_a, stack_b);
	else if (!strcmp(value, "rr\n"))
		rr(stack_a, stack_b);
	else if (!strcmp(value, "rrr\n"))
		rrr(stack_a, stack_b);
	else
	{
		free(value);
		get_next_line(-100);
		write(2, "Error\n", 6);
		free_all(stack_a, stack_b);
		exit(EXIT_FAILURE);
	}
}

static void	operations(t_stack **stack_a, t_stack **stack_b, char *value)
{
	if (!strcmp(value, "sa\n"))
		swap(stack_a);
	else if (!strcmp(value, "sb\n"))
		swap(stack_b);
	else if (!strcmp(value, "pa\n"))
		push(stack_a, stack_b, 'a');
	else if (!strcmp(value, "pb\n"))
		push(stack_a, stack_b, 'b');
	else if (!strcmp(value, "ra\n"))
		rotate(stack_a);
	else if (!strcmp(value, "rb\n"))
		rotate(stack_b);
	else
		double_ops(stack_a, stack_b, value);
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		operations(stack_a, stack_b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}
