/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <emollebr@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:22:19 by emollebr          #+#    #+#             */
/*   Updated: 2023/08/02 13:22:22 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_stack(char **args, int size)
{
	int		i;
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	if (!args)
		return (NULL);
	stack->val = ft_atoi(args[0]);
	i = 1;
	while (i < size)
	{
		stack_add_back(stack, ft_atoi(args[i]));
		i++;
	}
	return (stack);
}

void	index_stack(t_stack *stack, int ac)
{
	int		i;
	int		swap;
	t_stack	*head;

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

int	stack_size(t_stack *stack)
{
	int	size;

	size = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	stack_add_back(t_stack *lst, int content)
{
	t_stack	*old;
	t_stack	*new;

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
