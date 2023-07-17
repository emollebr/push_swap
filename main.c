#include "push_swap.h"

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

	printf("number being stacked is %i\n", content);
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

t_stack	*parse_stack(char **av, int ac)
{
	int		i;
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		stack_add_back(stack, ft_atoi(av[i]));
		i++;
	}
	return (stack);
}

int	a_is_sorted(t_stack	*ptr)
{
	printf("content is %d, next content is %d", ptr->val, 5);
	
	/*if (ptr->val > ptr->next->val && ptr->next != NULL)
		return (0);
	ptr = ptr->next;
	if (a_is_sorted(ptr) == 0)
		return (0);*/
	return (1);

}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		i;

	i = 1;
	//if (**error check here**)
	if (ac == 4)
		printf("%s\n", "3 elements");
	a_stack = parse_stack(av, ac);
	(void)b_stack;
	while (a_stack != NULL)
	{
		printf("content is %d at address %p\n", a_stack->val, &a_stack->val);
		a_stack = a_stack->next;
	}
	i = a_is_sorted(a_stack) == 1;
		printf("%s\n", "a is sorted");
	printf("address of stack** is %p\n", &(a_stack));
	//ft_lstclear(a_stack, free);
	//ft_lstiter(*a_stack, free);
	//free(*a_stack);
}
