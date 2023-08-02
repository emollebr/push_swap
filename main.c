/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <emollebr@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:00 by emollebr          #+#    #+#             */
/*   Updated: 2023/08/02 13:23:01 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index < stack->next->index)
			stack = stack->next;
		else 
				return (0);
	}
	return (1);
}

int argcheck(char **args, int size)
{
    int i;
    int j;

    i = 0;
    while (args[i])
    {
        j = 0;
        while (args[i][j] != '\0')
        {
            if (!ft_isdigit(args[i][j]) && args[i][j] != '-')
            {
                ft_printf("Error\n");
                exit(2);
            }
            j++;
        }
        j = 0;
        while (j < i)
        {
            if (ft_atoi(args[j]) == ft_atoi(args[i]))
            {
                ft_printf("Error\n");
                exit(2);
            }
            j++;
        }
        i++;
    }
    if (size == 0)
        exit (1);
    if (size == 2)
    {
       if (ft_atoi(args[0]) > ft_atoi(args[1]))
           write(1, "sa\n", 1);
        else
            write(1, "Stack is sorted!\n", 17);
       exit (1);
   }
	return (1);
}

int	arg_size(char **args)
{
	int	i;
	
	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

char	**av_to_arg(char **av, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j])
	{
		args[i] = av[j];
		i++;
		j++;
	}
	return (args);
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
	char	**args;
	int     size;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		size = arg_size(args);
		argcheck(args, size);
	}
	else
	{
		size = ac - 1;
		args = ft_calloc(8, size);
		if (!args)
			return (-1);
		args = av_to_arg(av, args);
		argcheck(args, size);
	}
	a_stack = ft_calloc(8, 1);
    b_stack = ft_calloc(8, 1);
    *a_stack = parse_stack(args, size);
    *b_stack = parse_stack(NULL, 0);
	index_stack(*a_stack, size + 1);
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
    free_tab(*a_stack);
    free_tab(*b_stack);
	free(args);
	return(0);
}
