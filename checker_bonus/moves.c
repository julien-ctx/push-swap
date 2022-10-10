/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:26:02 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/14 17:48:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr_bonus(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
}

void	rr_bonus(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
}

void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!str)
		return ;
	if (!ft_strncmp(str, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(stack_a, stack_b);
	else
		error();
}

void	pile_down(t_node *stack, t_node *node)
{
	t_node	*head;

	head = stack;
	while (head->next != stack)
	{
		if (head->nb == node->nb)
			error();
		head = head->next;
	}
	if (head->nb == node->nb)
		error();
	if (stack->next == stack && stack->prev == stack)
	{
		stack->next = node;
		stack->prev = node;
		node->prev = stack;
		node->next = stack;
		return ;
	}
	head = stack;
	node->prev = head->prev;
	head->prev->next = node;
	head->prev = node;
	node->next = head;
}
