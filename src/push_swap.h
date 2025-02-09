#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_divider(int len);
int		is_sorted_ascending(t_stack **stack);

void	swap(t_stack **stack, int c);
void	push(t_stack **stack_a, t_stack **stack_b, int c);
void	rotate(t_stack **stack, int c);
void	reverse_rotate(t_stack **stack, int c);

void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		pop(t_stack **stack);
void	new_node(t_stack **stack, int value);
void	error_check(int arg_num, char *argv[], t_stack **stack_a);

typedef struct s_sep
{
	int	min;
	int	mid_start;
	int	mid_end;
	int	max;
	int	len;
	int	div;
}	t_sep;

void	sort_three(t_stack **stack);
void	sort_two(t_stack **stack);

void	separate(t_stack **stack_a, t_stack **stack_b);

typedef struct s_value
{
	int	max;
	int	max_index;
	int	len;
}	t_value;

typedef struct s_check
{
	int		first;
	int		second;
	int		min_val;
	int		index;
	bool	check;
}	t_check;

void	sort_all(t_stack **stack_a, t_stack **stack_b);

#endif
