#include "push_swap.h"
#include "push_swap.h"

t_stack *stack_last(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}
void    stack_add_back(t_stack *lst, int content)
{
    t_stack *old;
    t_stack *new;

    new = ft_calloc(sizeof(t_stack), 1);
    if (new == NULL)
        return ;
    new->val = content;
    new->next = NULL;
    if (lst == NULL)
    {
        lst = new;
        return ;
    }
    old = stack_last(lst);
    old->next = new;
    return ;
}

void	print_stack (t_stack *stack, int size)
{
    int i;

    i = 1;
	while (i < size)
	{
		ft_printf("val: %d\n", stack->val);
		stack = stack -> next;
        i++;
	}
	ft_printf("val: %d\n", stack->val);
	ft_printf("\n");
}

t_stack *parse_stack(char **av, int size)
{
    int     i;
    t_stack *stack;

    stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
    if (stack == NULL)
        return (NULL);
    stack->val = ft_atoi(av[1]);
    i = 2;
    while (i <= size)
    {
        stack_add_back(stack, ft_atoi(av[i]));
        i++;
    }
    return (stack);
}

void index_stack(t_stack *stack, int ac)
{
    int i;
    int swap;
    t_stack *head;
    
    i = 0;
    head = stack;
    swap = INT_MAX; 
    stack = head;
    while (i < ac)
    {
        while (stack != NULL)
        {
            if (stack->val == swap && stack->index == 0)
                stack->index = i;	
            stack = stack->next;
        }
        stack = head;
        swap = INT_MAX;
        while (stack != NULL)
        {
            if (stack->index == 0 && swap > stack->val)
                swap = stack->val;
            stack = stack->next;
        }
        stack = head;
        i++;
    }
}

int radix_sort(t_stack *a, t_stack *b, int size)
{
    int max_bits;
    int i;
    int j;
    int num;

    i = 0;
    j = 0;
    max_bits = 0;
    while (~(size >> max_bits) == 0)
        max_bits++;
    while (i < max_bits)
    {
        while (j < size)
        { 
            num = a->index;
            if (((num >> i)&1) == 1)
                rotate(a, "ra");
            else
                push(&b, &a, "pb");
            j++;
        }
        j = 0;
        i++;
        while (b != NULL)
            push(&a, &b, "pa");
    }
    return (1);
}

void	print_index (t_stack *stack, int size)
{
    int i;

    i = 1;
	while (i < size)
	{
		ft_printf("ind: %d\n", stack->index);
		stack = stack -> next;
        i++;
	}
	ft_printf("ind: %d\n", stack->index);
	ft_printf("\n");
}

int main(int ac, char **av)
{
    t_stack *a_stack;
 	t_stack *b_stack;
    int         size;    

    size = ac - 1;
    a_stack = parse_stack(av, size);
    b_stack = NULL;
    index_stack(a_stack, ac);
	print_stack(a_stack, size);
    print_index(a_stack, size);
    radix_sort(a_stack, b_stack, size);
    print_stack(a_stack, size);
	return(0);
}