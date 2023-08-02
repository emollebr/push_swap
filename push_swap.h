/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emollebr <emollebr@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:22:01 by emollebr          #+#    #+#             */
/*   Updated: 2023/08/02 13:22:05 by emollebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./my_lib.h"
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int		val;
	int		index;
	struct s_stack		*next;
}		t_stack;

int	stack_size(t_stack *stack);
t_stack		*parse_stack(char **av, int size);
t_stack		*stack_last(t_stack *lst);
void		stack_add_back(t_stack *lst, int content);
void		index_stack(t_stack *stack, int ac);

int	argcheck(char **args, int size);
int	is_sorted(t_stack *stack);
void	sort_stack(t_stack **a_stack, t_stack **b_stack, int size);
int	args_handling(char **av, int ac);

int	get_size(char **args, int size);
int	free_tab(t_stack *stack);
char		**av_to_arg(char **av, char **args);
void	if_args(char **args, int i, int j, int x);
void	index_util(t_stack **stack, int i, int swap);

int	swap(t_stack **a_stack, char *op);
int	ss(t_stack **a_stack, t_stack **b_stack);
int	push(t_stack **a_stack, t_stack **b_stack, char *op);
int	rotate(t_stack **a_stack, char *op);
int	revrot(t_stack **a, char *op);

void		if_3(int *pos, t_stack **a);
int		sort_3(t_stack **a_stack);
int		sort_4(t_stack **a_stack, t_stack **b_stack);
int		sort_5(t_stack **a_stack, t_stack **b_stack);
t_stack	**radix_sort(t_stack **a, t_stack **b);

#endif
