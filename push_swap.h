#ifndef PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <stdio.h>
# include "./my_lib.h"
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
    int             val;
    int             index;
    struct s_stack  *next;
}               t_stack;


int stack_size(t_stack *stack);
t_stack *parse_stack(char **av, int size);
t_stack *stack_last(t_stack *lst);
void    stack_add_back(t_stack *lst, int content);
void index_stack(t_stack *stack, int ac);

int argcheck(char **av, int ac);
int free_tab(t_stack *stack);
int is_sorted(t_stack *stack);

int swap(t_stack **a_stack, char *op);
int	ss(t_stack **a_stack, t_stack **b_stack);
int	push(t_stack **a_stack, t_stack **b_stack, char *op);
int	rotate(t_stack **a_stack, char *op);
int revrot(t_stack **a, char *op);

int sort_3(t_stack **a_stack);
int sort_4(t_stack **a_stack, t_stack **b_stack);
int sort_5(t_stack **a_stack, t_stack **b_stack);
t_stack **radix_sort(t_stack **a, t_stack **b);
/*void print_stack (t_stack *stack);
void print_index (t_stack *stack);*/

#endif