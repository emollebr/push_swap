#include "push_swap.h"
#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> index < stack -> next -> index)
			stack = stack -> next;
		else 
			{
				ft_printf("Stack is nicht sorted!\n");
				return (0);
			}
	}
	ft_printf("Stack is sorted!\n");
	return (1);
}

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

void	print_stack (t_stack *stack)
{
    int i;
    int size;

    if (!stack)
        return ;
    size =  stack_size(stack);
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
    if (!av)
        return (stack = NULL);
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

t_stack *radix_sort(t_stack *a, t_stack *b)
{
    int max_bits;
    int i;
    int j;
    int num;
    int size;

    i = 0;
    j = 0;
    max_bits = 0;
    size = stack_size(a);
    while ((size >> max_bits) != 0)
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
    return (a);
}

int stack_size(t_stack *stack)
{
    int size;

    size = 1;
    while (stack->next != NULL)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}

void	print_index (t_stack *stack)
{
    int i;
    int size;

    if (!stack)
        return ;
    i = 1;
    size = stack_size(stack);
	while (i < size)
	{
		ft_printf("index: %d\n", stack->index);
		stack = stack -> next;
        i++;
	}
	ft_printf("index: %d\n", stack->index);
	ft_printf("\n");
}

int main(int ac, char **av)
{
    t_stack *a_stack;
 	t_stack *b_stack;
    int         size;    

    size = ac - 1;
    a_stack = parse_stack(av, size);
    b_stack = parse_stack(NULL, 0);
    index_stack(a_stack, ac);
 ft_printf("first stack A:\n");
    print_stack(a_stack); 
    print_index(a_stack);
    /*if (rotate(a_stack, "ra"))
         print_stack(a_stack);
    if (push(&a_stack, &b_stack, "pa"))
        print_stack(a_stack);
    if (push(&b_stack, &a_stack, "pb"))*/
    
    a_stack = radix_sort(a_stack, b_stack);
    //push(&b_stack, &a_stack, "pb");
    ft_printf("final stack A:\n");
    print_stack(a_stack); 
    print_index(a_stack);
	return(0);
}