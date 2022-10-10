/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:01:14 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/14 17:57:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	if (!*stack)
		return ;
	node = *stack;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	if (!*stack)
		return ;
	node = *stack;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sb\n", 3);
}
