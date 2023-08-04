/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <emollebr@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:22:43 by emollebr          #+#    #+#             */
/*   Updated: 2023/08/02 13:22:44 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **a_stack, char *op)
{
	int	swap;
	int	swap_index;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return (-1);
	swap = (*a_stack)->val;
	swap_index = (*a_stack)->index;
	(*a_stack)->val = (*a_stack)->next->val;
	(*a_stack)->index = (*a_stack)->next->index;
	(*a_stack)->next->val = swap;
	(*a_stack)->next->index = swap_index;
	if (op != NULL)
	{
		ft_putstr_fd(op, 1);
		write(1, "\n", 1);
	}
	return (1);
}

int	ss(t_stack **a_stack, t_stack **b_stack)
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
	t_stack *tmp;

	if (*b_stack == NULL)
		return (0);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->val = (*b_stack)->val;
	new->index = (*b_stack)->index;
	new->next = (*a_stack);
	(*a_stack) = new;
	tmp = *b_stack;
	(*b_stack) = (*b_stack)->next;
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	free(tmp);
	return (1);
}

int	rotate(t_stack **a_stack, char *op)
{
	t_stack	*first_node;
	t_stack	*current_node;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return (-1);
	first_node = *a_stack;
	*a_stack = (*a_stack)->next;
	current_node = *a_stack;
	while (current_node->next != NULL)
	current_node = current_node->next;
	current_node->next = first_node;
	first_node->next = NULL;
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	return (1);
}

int	revrot(t_stack **a_stack, char *op)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	last_node = *a_stack;
	second_last_node = NULL;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node -> next;
	}
	last_node -> next = *a_stack;
	*a_stack = last_node;
	second_last_node -> next = NULL;
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	return (1);
}
