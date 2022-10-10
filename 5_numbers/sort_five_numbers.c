/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:38:03 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/04 12:04:55 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	size_five(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 5)
	{
		if ((*stack_b)->nb < (*stack_a)->nb
			&& (*stack_b)->nb > (*stack_a)->prev->nb)
		{
			pa(stack_a, stack_b);
			rra(stack_a, 1);
			rra(stack_a, 1);
			return (1);
		}
	}
	return (0);
}

int	push_rules_1(t_node **stack_a, t_node **stack_b, int size)
{
	if ((*stack_b)->nb > (*stack_a)->prev->nb)
	{
		pa(stack_a, stack_b);
		ra(stack_a, 1);
	}
	else if ((*stack_b)->nb < (*stack_a)->nb)
		pa(stack_a, stack_b);
	else if ((*stack_b)->nb > (*stack_a)->nb
		&& (*stack_b)->nb < (*stack_a)->next->nb)
	{
		pa(stack_a, stack_b);
		sa(stack_a, 1);
	}
	else if ((*stack_a)->prev->nb > (*stack_b)->nb
		&& (*stack_b)->nb > (*stack_a)->prev->prev->nb)
	{
		rra(stack_a, 1);
		pa(stack_a, stack_b);
		if (size_five(stack_a, stack_b, size))
			return (0);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	return (1);
}

void	last_case(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 1);
	ra(stack_a, 1);
	pa(stack_a, stack_b);
	rra(stack_a, 1);
	rra(stack_a, 1);
}

void	push_rules_2(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_b)->nb < (*stack_a)->nb)
		pa(stack_a, stack_b);
	else if ((*stack_b)->nb > (*stack_a)->prev->nb)
	{
		pa(stack_a, stack_b);
		ra(stack_a, 1);
	}
	else if ((*stack_b)->nb > (*stack_a)->nb
		&& (*stack_b)->nb < (*stack_a)->next->nb)
	{
		pa(stack_a, stack_b);
		sa(stack_a, 1);
	}
	else if ((*stack_b)->nb < (*stack_a)->prev->nb
		&& (*stack_b)->nb > (*stack_a)->prev->prev->nb)
	{
		rra(stack_a, 1);
		pa(stack_a, stack_b);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else
		last_case(stack_a, stack_b);
}

void	sort_five_numbers(t_node **stack_a, t_node **stack_b)
{
	if (stack_size((*stack_a)) == 4)
	{
		if ((*stack_a)->nb < (*stack_a)->next->nb
			&& (*stack_a)->next->nb < (*stack_a)->next->next->nb
			&& (*stack_a)->prev->nb > (*stack_a)->prev->prev->nb)
			return ;
		pb(stack_a, stack_b);
		sort_three_numbers(stack_a);
		push_rules_1(stack_a, stack_b, 4);
	}
	else
	{
		if (((*stack_a)->nb < (*stack_a)->next->nb)
			&& ((*stack_a)->next->nb < (*stack_a)->next->next->nb)
			&& ((*stack_a)->next->next->nb < (*stack_a)->prev->prev->nb)
			&& ((*stack_a)->prev->prev->nb < (*stack_a)->prev->nb))
			return ;
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sort_three_numbers(stack_a);
		if (push_rules_1(stack_a, stack_b, 5))
			push_rules_2(stack_a, stack_b);
	}
}
