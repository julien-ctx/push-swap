/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:17:54 by juliencauch       #+#    #+#             */
/*   Updated: 2022/11/05 15:08:55 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_good_sort(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;

	if (stack_b)
		return (0);
	node = stack_a;
	while (node->next->next != stack_a)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	if (node->nb > node->next->nb)
		return (0);
	return (1);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	node->nb = value;
	node->ra = 0;
	node->rb = 0;
	node->rra = 0;
	node->rrb = 0;
	return (node);
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
		{
			write(2, "Error\n", 6);
			exit(1);
		}
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

t_node	*stack_a_init(t_node *stack, char **array)
{
	int	i;

	stack = create_node(ft_atoi(array[0]));
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
		pile_down(stack, create_node(ft_atoi(array[i++])));
	return (stack);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (1);
	stack_a = NULL;
	array = NULL;
	array = args_handler(&ac, av);
	stack_a = stack_a_init(stack_a, array);
	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0);
		do_moves_bonus(str, &stack_a, &stack_b);
		free(str);
	}
	if (check_good_sort(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
