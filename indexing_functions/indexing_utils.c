/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:31:45 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/07 10:12:08 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prepare_swap_index(int max, t_node **node, int a)
{
	if (a)
		while ((*node)->index != max)
			*node = (*node)->next;
	else
		while ((*node)->index != max)
			*node = (*node)->prev;
}

int	partition(t_node *stack, int *array, int start, int end)
{
	int		i;
	int		j;
	t_node	*node_start;
	t_node	*node_end;

	i = 0;
	j = 0;
	while (end - j > start + i)
	{
		while ((array[start] > array[start + i]))
			i++;
		while ((array[start] < array[end - j]))
			j++;
		if (end - j < start + i)
			break ;
		ft_swap(&array[start + i], &array[end - j]);
		node_start = stack;
		node_end = stack->prev;
		prepare_swap_index(start + i, &node_start, 1);
		prepare_swap_index(end - j, &node_end, 0);
		ft_swap(&node_start->index, &node_end->index);
	}
	ft_swap(&array[start], &array[end - j]);
	return (end - j);
}

void	quicksort(t_node *stack, int *array, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(stack, array, start, end);
		quicksort(stack, array, start, pivot - 1);
		quicksort(stack, array, pivot + 1, end);
	}
}

void	index_init(t_node *stack)
{
	int		*array;
	int		i;
	t_node	*node;

	array = NULL;
	array = stack_dup(array, stack);
	node = stack;
	i = 0;
	while (node->next != stack)
	{
		node->index = i++;
		node = node->next;
	}
	node->index = i;
	quicksort(stack, array, 0, stack_size(stack) - 1);
	node = stack;
	free(array);
}
