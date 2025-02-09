#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	swap(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b, int c);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		pop(t_stack **stack);
void	new_node(t_stack **stack, int value);
void	error_check(int argc, char *argv[], t_stack **stack_a);

size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, const char *s2);

char	*get_next_line(int fd);

void	free_all(t_stack **stack_a, t_stack **stack_b);
void	read_input(t_stack **stack_a, t_stack **stack_b);

#endif
