#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_lib.h"

typedef struct s_stack
{
    int             val;
    int             index;
    struct s_stack  *next;
}               t_stack;


int	swap(t_list *stack);
int	push(t_list *a_stack, t_list *b_stack);
int	rotate(t_list *stack);
int	rev_rotate(t_list *stack);

int	sa(t_list *a_stack);
int	sb(t_list *b_stack);
int	ss(t_list *a_stack, t_list *b_stack);
int	pa(t_list *a_stack, t_list *b_stack);
int	pb(t_list *b_stack, t_list *a_stack);

int	ra(t_list *a_stack);
int	rb(t_list ba_stack);
int	rra(t_list *a_stack);
int	rrb(t_list *b_stack);
int	rrr(t_list *a_stack, t_list *b_stack);

#endif