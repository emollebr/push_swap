#include "push_swap.h"

char	**av_to_arg(char **av, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	args = ft_calloc(8, (get_size(av, -1) + 1));
	if (!args)
		return (NULL);
	while (av[j])
	{
		args[i] = ft_strdup(av[j]);
		i++;
		j++;
	}
	args[i] = NULL;
	return (args);
}

void	free_tab(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	stack = NULL;
	return ;
}

void free_arr(char **arr) 
{
	int	i;

	i = 0;
    if (arr == NULL) 
		return;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
    free(arr);
}

int	get_size(char **args, int size)
{
	int	i;

	i = 0;
	if (size < 0)
	{
		while (args[i] != NULL)
			i++;
	}
	else if (!args)
	{
		while ((size >> i) != 0)
			i++;
	}
	return (i);
}

void	if_args(char **args, int i, int j, int x)
{
	if (x == 1)
	{
		if (!ft_isdigit(args[i][j]) && args[i][j] != '-')
		{
			ft_printf("Error\n");
			exit(2);
		}
	}
	if (x == 2)
	{
		if (ft_atoi(args[j]) == ft_atoi(args[i]))
		{
			ft_printf("Error\n");
			exit(2);
		}
	}
	return ;
}

void	index_util(t_stack *stack, int i, int swap)
{
	while (stack != NULL)
	{
		if (stack->val == swap && stack->index == 0)
			stack->index = i;
		stack = stack->next;
	}
}
