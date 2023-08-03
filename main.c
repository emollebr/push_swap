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

int	is_sorted(t_stack *stack)
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

int	argcheck(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if_args(args, i, j, 1);
			j++;
		}
		j = 0;
		while (j < i)
		{
			if_args(args, i, j, 2);
			j++;
		}
		i++;
	}
	return (1);
}

void	sort_stack(t_stack **a_stack, t_stack **b_stack, int size)
{
	index_stack(*a_stack, size + 1);
	if (is_sorted(*a_stack))
		return ;
	if (size == 3)
		sort_3(a_stack);
	if (size == 4)
		sort_4(a_stack, b_stack);
	if (size == 5)
		sort_5(a_stack, b_stack);
	if (size > 5)
		a_stack = radix_sort(a_stack, b_stack);
}

char	**args_handling(char **av, int ac)
{
	char	**args;

	args = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		argcheck(args);
	}
	else
	{
		args = av_to_arg(av, args);
		argcheck(args);
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**args;
	int		size;


		ft_printf("%p\n", av[1][1]);
	args = args_handling(av, ac);
	size = get_size(args, -1);
	if (size == 0)
		exit (1);
	if (size == 2)
	{
		if (ft_atoi(args[0]) > ft_atoi(args[1]))
			write(1, "sa\n", 1);
		exit (1);
	}
	//a_stack = ft_calloc(size, sizeof(t_stack));
	//b_stack = ft_calloc(1, 8);
	a_stack = parse_stack(args, size);
	b_stack = parse_stack(NULL, 1);
	sort_stack(&a_stack, &b_stack, size);
	// int n = 0;
	free_arr(args, size);
	free_tab(&a_stack);
	free_tab(&b_stack);
	return (0);
}
