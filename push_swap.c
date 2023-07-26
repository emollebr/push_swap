#include "push_swap.h"

int	swap(t_stack *stack, char *op)
{
	t_stack *tmp;

	if (stack->next == NULL)
		return(0);
	tmp = stack->next;
	stack->next = stack;
	stack = tmp;
	return (1);
	if (op != NULL)
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	return(1);
}

int	ss(t_stack *a_stack, t_stack *b_stack)
{
	swap(a_stack, NULL);
	swap(b_stack, NULL);
	ft_putstr_fd("ss", 1);
	write(1, "\n", 1);
	return (1);
}

int	push(t_stack **a_stack, t_stack **b_stack, char *op)
{
	t_stack	*new;

	if ((*b_stack) == NULL)
		return (0); 
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->val = (*b_stack)->val;
	new->index = (*b_stack)->index;
	new->next = (*a_stack);
	(*a_stack) = new;
	(*b_stack) = (*b_stack)->next;
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	//free(new);
	return (1);
}

int	rotate(t_stack *a_stack, char *op)
{
    int first_val; 
    int first_index;

	if (!a_stack)
		return (0);
	first_val = a_stack->val;
	first_index = a_stack->index;
    while (a_stack->next != NULL)
    {
        a_stack->val = a_stack->next->val;
        a_stack->index = a_stack->next->index;
        a_stack = a_stack->next;
    }
    a_stack->val = first_val;
    a_stack->index = first_index;
    a_stack->next = NULL;
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	return (1);
}