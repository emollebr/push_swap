#include "push_swap.h"

int	sa(t_list *a_stack)
{
	if (swap(a_stack))
	{
		ft_putendl_fd("sa", 1);
		return (1);
	}
	return (0);
}

int	sb(t_list *b_stack)
{
	if (swap(b_stack))
	{
		ft_putendl_fd("sb", 1);
		return (1);
	}
	return (0);
}

int	ss(t_list *a_stack, t_list *b_stack)
{
	if (swap(a_stack) && swap(b_stack))
	{
		ft_putendl_fd("ss", 1);
		return (1);
	}
	return (0);
}

int	pa(t_list *a_stack, t_list *b_stack)
{
	if (push(a_stack, b_stack))
	{
		ft_putendl_fd("pa", 1);
		return (1);
	}
	return (0);
}

int	pb(t_list *b_stack, t_list *a_stack)
{
	if (push(b_stack, a_stack))
	{
		ft_putendl_fd("pb", 1);
		return (1);
	}
	return (0);
}