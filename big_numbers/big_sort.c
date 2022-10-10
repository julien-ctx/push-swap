/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:47:10 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/07 14:39:41 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_last_index(t_node **stack, t_node *node, t_max *max, int j)
{
	if (node->index == 0)
	{
		if (max->nb <= max->size / 2)
			while (j++ < max->nb)
				ra(stack, 1);
		else
			while (j++ < max->size - max->nb)
				rra(stack, 1);
	}
}

void	reorder(t_node **stack, int size, int index)
{
	t_node	*node;
	int		i;
	int		j;

	node = *stack;
	i = 0;
	j = 0;
	while (node->next != *stack)
	{
		if (node->index == index)
		{
			if (i <= size / 2)
				while (j++ < i)
					ra(stack, 1);
			else
				while (j++ < size - i)
					rra(stack, 1);
			return ;
		}
		i++;
		node = node->next;
	}
	check_last_index(stack, node, &((t_max){i, size}), j);
}

void	check_sa_needed(t_node **stack, t_seq **seq)
{
	t_seq	*fake_seq;

	sa(stack, 0);
	fake_seq = sequence(stack);
	if (fake_seq->max_len > (*seq)->max_len)
	{
		write(1, "sa\n", 3);
		markup(stack, fake_seq);
		free(*seq);
		*seq = fake_seq;
	}
	else
	{
		free(fake_seq);
		sa(stack, 0);
	}
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	t_seq	*seq;
	int		i;
	int		size;

	seq = sequence(stack_a);
	markup(stack_a, seq);
	check_sa_needed(stack_a, &seq);
	free(seq);
	i = 0;
	size = stack_size(*stack_a);
	while (i <= size)
	{
		if (!((*stack_a)->value))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
	while (*stack_b)
	{
		moves_init(stack_b, 0);
		find_best_push(stack_a, stack_b);
	}
	reorder(stack_a, size, 0);
}
