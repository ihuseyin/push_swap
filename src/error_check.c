#include "push_swap.h"

static void	duplicate_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_stack;

	current = *stack;
	while (current && current->next)
	{
		next_stack = current->next;
		while (next_stack)
		{
			if (current->value == next_stack->value)
			{
				write(2, "Error\n", 6);
				while (*stack)
					pop(stack);
				exit(3);
			}
			next_stack = next_stack->next;
		}
		current = current->next;
	}
}

static int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = +1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = sign * result;
	if (*str || result > 2147483647 || result < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(2);
	}
	return (result);
}

void	error_check(int argc, char *argv[], t_stack **stack_a)
{
	int		arg_num;

	if (argc <= 2)
		exit(1);
	arg_num = argc - 1;
	while (arg_num > 0)
	{
		new_node(stack_a, ft_atoi(argv[arg_num]));
		arg_num--;
	}
	duplicate_check(stack_a);
}
