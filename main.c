#include "push_swap.h"

/*void	print_stack (t_stack *stack)
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
*/
/*void	print_index (t_stack *stack)
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
*/
int is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index < stack->next->index)
			stack = stack->next;
		else 
				return (0);
	}
	ft_printf("Stack is sorted!\n");
	return (1);
}

int argcheck(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    //missing limits for int size
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
            {
                ft_printf("Error\n");
                exit(2);
            }
            j++;
        }
        j = 0;
        while (j < i)
        {
            if (ft_atoi(av[j]) == ft_atoi(av[i]))
            {
                ft_printf("Error\n");
                exit(2);
            }
            j++;
        }
        i++;
    } 
    if (ac < 2)
        exit (1);
    if (ac == 3)
    {
       if (ft_atoi(av[1]) > ft_atoi(av[2]))
           write(1, "sa\n", 1);
        else
            write(1, "Stack is sorted!\n", 17);
       exit (1);
   }
    return(1);
}

int free_tab(t_stack *stack)
{
    t_stack *tmp;
    t_stack *current;

   current = stack;
    while (current)
    {   
        tmp = current;
        current = current->next;
        free(tmp);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_stack **a_stack;
 	t_stack **b_stack;
    int         size; 

    argcheck(av, ac);
    size = ac - 1;
    a_stack = ft_calloc(8, 1);
    b_stack = ft_calloc(8, 1);
    *a_stack = parse_stack(av, size);
    *b_stack = parse_stack(NULL, 0);
    index_stack(*a_stack, ac);
    if(is_sorted(*a_stack))
        return (0);
    if (size == 3)
        sort_3(a_stack);
    if (size == 4)
        sort_4(a_stack, b_stack);
    if (size == 5)
        sort_5(a_stack, b_stack);
    if (size > 5)
    a_stack = radix_sort(a_stack, b_stack);
   // print_stack(*a_stack);
    free_tab(*a_stack);
    free_tab(*b_stack);
	return(0);
}