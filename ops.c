#include "push_swap.h"

int	swap(t_list *stack)
{
	t_list	*tmp;

	if (ft_lstsize(stack) < 2)
		return (0);
	tmp = stack->next;
	stack->next = stack;
	stack = tmp;
	return (1);
}

int	push(t_list *dest, t_list *stack)
{
	t_list	*tmp;
	if (!stack)
		return (0);
	ft_lstadd_front(&dest, stack->content);
	tmp = stack->next;
	stack = tmp;
	return (0);
}

int	rotate(t_list *stack)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(stack) < 2)
		return (0);
	first = stack;
	last = ft_lstlast(stack);
	last->next = first;
	stack = first->next;
	first->next = NULL;
	return (1);
}


int	rev_rotate(t_list *stack)
{
	t_list	*tmp;

	if (ft_lstsize(stack) < 2)
		return (0);
	tmp = ft_lstlast(stack);
	while (stack)
	{
		if (stack->next == tmp)
		{
			stack->next = NULL;
			break ;
		}
		stack = stack->next;
	}
	ft_lstadd_front(&stack, tmp);
	return (1);
}