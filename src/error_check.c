#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void	write_error(int *list)
{
	write(STDOUT_FILENO, "Error\n", 6);
	free(list);
	exit(EXIT_FAILURE);
}

static int	sort_duplicate_check(int len, int *list, int *sorted)
{
	int	swapped;
	int	temp;
	int	j;

	swapped = 0;
	temp = 0;
	j = 0;
	while (j < len)
	{
		if (sorted[j] == sorted[j + 1])
		{
			free(sorted);
			write_error(list);
		}
		if (sorted[j] > sorted[j + 1])
		{
			temp = sorted[j];
			sorted[j] = sorted[j + 1];
			sorted[j + 1] = temp;
			swapped = 1;
		}
		j++;
	}
	return (swapped);
}

static void	sort_and_assign(int len, int *list, int *sorted)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < len)
		sorted[i] = list[i];
	i = -1;
	while (i++ < len)
		if (!sort_duplicate_check(len - i, list, sorted))
			break ;
	i = -1;
	while (i++ < len)
	{
		j = -1;
		while (j++ < len)
		{
			if (list[i] == sorted[j])
			{
				list[i] = j + 1;
				break ;
			}
		}
	}
	free(sorted);
}

static int	ft_atoi(const char *str, int *list)
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
		write_error(list);
	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = sign * result;
	if (str[i] || result > INT_MAX || result < INT_MIN || i > 10)
		write_error(list);
	return (result);
}

void	error_check(int len, char *argv[], t_stack **stack_a)
{
	int	*list;
	int	*sorted;
	int	index;

	if (len <= 1)
	{
		if (len == 1)
			ft_atoi(argv[1], NULL);
		exit(EXIT_FAILURE);
	}
	list = malloc(len * sizeof(int));
	if (!list)
		write_error(NULL);
	index = -1;
	while (index++ < len - 1)
		list[index] = ft_atoi(argv[index + 1], list);
	sorted = malloc(len * sizeof(int));
	if (!sorted)
		write_error(list);
	sort_and_assign(len - 1, list, sorted);
	while (len-- > 0)
		new_node(stack_a, list[len]);
	free(list);
}
