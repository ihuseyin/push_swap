#include "checker.h"
#include <unistd.h>
#include <limits.h>

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

static void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

static int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	sign = +1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!*str)
		write_error();
	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = sign * result;
	if (str[i] || result > INT_MAX || result < INT_MIN || i > 10)
		write_error();
	return (result);
}

void	error_check(int argc, char *argv[], t_stack **stack_a)
{
	int		arg_num;

	if (argc == 1)
		exit(1);
	arg_num = argc - 1;
	if (argc == 2)
		ft_atoi(argv[arg_num]);
	while (arg_num > 0)
	{
		new_node(stack_a, ft_atoi(argv[arg_num]));
		arg_num--;
	}
	duplicate_check(stack_a);
}
