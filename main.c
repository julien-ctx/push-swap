/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:10:58 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/07 15:24:55 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_one_arg(char *str, char **array)
{
	int	i;

	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		ft_free_array(array);
		error();
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= 48 && str[0] <= 57)))
	{
		ft_free_array(array);
		error();
	}
	i = 0;
	while (str[++i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			ft_free_array(array);
			error();
		}
	}
	ft_atoi(str);
	ft_free_array(array);
	exit(0);
}

char	**args_handler(int *ac, char **av)
{
	char	**array;
	int		i;

	if (*ac < 2)
		exit(1);
	else if (*ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array)
			exit(1);
		else if (!array[1])
			test_one_arg(array[0], array);
		*ac = ft_array_size(array);
	}
	else
	{
		i = 0;
		array = malloc(sizeof(char *) * (*ac));
		while (++i < *ac)
			array[i - 1] = ft_strdup(av[i]);
		array[i - 1] = NULL;
		(*ac)--;
	}
	return (array);
}

void	order_checker(t_node *stack)
{
	t_node	*node;

	node = stack;
	while (node->next != stack)
	{
		if (node->nb > node->next->nb)
			return ;
		node = node->next;
	}
	exit(0);
}

void	moves_init(t_node **stack_a, int n)
{
	t_node	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		node->sa = n;
		node->sb = n;
		node->ra = n;
		node->rb = n;
		node->rra = n;
		node->rrb = n;
		node->move = n;
		node = node->next;
	}
	node->sa = n;
	node->sb = n;
	node->ra = n;
	node->rb = n;
	node->rra = n;
	node->rrb = n;
	node->move = n;
}

int	main(int ac, char **av)
{
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	array = NULL;
	array = args_handler(&ac, av);
	stack_a = stack_a_init(stack_a, array);
	order_checker(stack_a);
	stack_b = NULL;
	if (ac <= 3)
		sort_three_numbers(&stack_a);
	else if (ac <= 5)
		sort_five_numbers(&stack_a, &stack_b);
	else
	{
		index_init(stack_a);
		big_sort(&stack_a, &stack_b);
	}
	ft_free_array(array);
	ft_free_stack(&stack_a, stack_size(stack_a));
}
