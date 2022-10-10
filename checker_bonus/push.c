/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:34:32 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/04 17:29:04 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pointers_init(t_node **l, t_node **n, t_node **s, t_node **stack)
{
	*l = (*stack)->prev;
	*n = *stack;
	*s = (*stack)->next;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*last;
	t_node	*second;
	int		a;

	if (!(*stack_b))
		return ;
	a = 1;
	if ((*stack_b)->next == *stack_b && (*stack_b)->prev == *stack_b)
		a = 0;
	pointers_init(&last, &node, &second, stack_b);
	node->next = *stack_a;
	(*stack_a)->prev->next = node;
	node->prev = (*stack_a)->prev;
	(*stack_a)->prev = node;
	*stack_a = node;
	if (!a)
		*stack_b = NULL;
	else
	{
		*stack_b = second;
		(*stack_b)->prev = last;
		last->next = *stack_b;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	if (!(*stack_a))
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = node->prev;
	(*stack_a)->prev->next = *stack_a;
	if (!(*stack_b))
	{	
		node->prev = node;
		node->next = node;
		*stack_b = node;
	}
	else
	{
		node->next = *stack_b;
		node->prev = (*stack_b)->prev;
		*stack_b = node;
		(*stack_b)->prev->next = *stack_b;
		(*stack_b)->next->prev = *stack_b;
	}
}
