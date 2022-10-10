/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:07:26 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/05 13:33:48 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_node **stack, int size)
{
	t_node	*node;
	int		i;

	i = 0;
	node = *stack;
	while (i < size - 1)
	{
		node = node->next;
		free(node->prev);
		i++;
	}
	free(node);
}
