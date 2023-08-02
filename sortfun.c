#include "push_swap.h"

int sort_3(t_stack **a_stack) 
{
    int		i;
    int pos[3];
    t_stack	*stack;

    if (!(*a_stack))
        return -1;
    i = 0;
    stack = *a_stack;
    while (stack && i < 3) 
    {
        pos[i] = stack->index;
        stack = stack->next;
        i++;
    }
    if (pos[0] < pos[1] && pos[1] < pos[2])
        return (0);
    else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] > pos[0])
        swap(a_stack, "sa");
    else if (pos[0] > pos[1] && pos[1] > pos[2])
    {
        swap(a_stack, "sa");
        revrot(a_stack, "rra");
    }
    else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] < pos[0])
        rotate(a_stack, "ra");
    else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] > pos[0])
    {
        swap(a_stack, "sa");
        rotate(a_stack, "ra");
    }
    else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] < pos[0])
        revrot(a_stack, "rra");
    return (1);
}

int sort_4(t_stack **a_stack, t_stack **b_stack)
{
	if (!(*a_stack))
		return (-1);
	while ((*a_stack)->index != 1)
			rotate(a_stack, "ra");
	push(b_stack, a_stack, "pb");
    if (!is_sorted(*a_stack))
	    sort_3(a_stack);
	push(a_stack, b_stack, "pa");
	return (0);
}

int sort_5(t_stack **a_stack, t_stack **b_stack)
{
	if (!(*a_stack))
		return (-1);
	while ((*a_stack)->index != 1)
			rotate(a_stack, "ra");
	push(b_stack, a_stack, "pb");
    while ((*a_stack)->index != 2)
			rotate(a_stack, "ra");
	push(b_stack, a_stack, "pb");
    if (!is_sorted(*a_stack))
	    sort_3(a_stack);
    while ((*b_stack)->index != 2)
    {
        rotate(b_stack, "rb");
    }
	push(a_stack, b_stack, "pa");
    push(a_stack, b_stack, "pa");
	return (0);
}

t_stack **radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;
    int i;
    int j;
    int num;
    int size;

    i = 0;
    j = 0;
    max_bits = 0;
    size = stack_size(*a);
    while ((size >> max_bits) != 0)
        max_bits++;
    while (i < max_bits)
    {
        while (j < size)
        { 
            num = (*a)->index;
            if (((num >> i)&1) == 1)
                rotate(a, "ra");
            else
                push(b, a, "pb");
            j++;
        }
        j = 0;
        i++;
        while (*b != NULL)
            push(a, b, "pa");
    }
    return (a);
}