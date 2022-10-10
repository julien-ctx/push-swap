/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:12:55 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/07 21:41:53 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index(t_node *stack_a, t_node *b, int max, t_node *node)
{
	int		index;
	int		i;

	i = 0;
	while (node->next != stack_a)
	{
		if (b->nb > node->nb)
		{
			if (node->nb > max)
			{
				max = node->nb;
				index = i;
			}
		}
		node = node->next;
		i++;
	}
	if (b->nb > node->nb)
		if (node->nb > max)
			index = i;
	return (index);
}

int	is_max(t_node *stack_a, t_node *b)
{
	t_node	*node;
	int		max;

	node = stack_a;
	while (node->next != stack_a)
	{
		if (node->nb > b->nb)
			return (-1);
		node = node->next;
	}
	if (node->nb > b->nb)
		return (-1);
	node = stack_a;
	max = -2147483648;
	return (find_index(stack_a, b, max, node));
}
