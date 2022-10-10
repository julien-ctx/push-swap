/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:05:34 by juliencauch       #+#    #+#             */
/*   Updated: 2022/03/07 09:39:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

void	sa(t_node **stack, int a);
void	sb(t_node **stack, int a);
void	ra(t_node **stack, int a);
void	rb(t_node **stack, int a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack, int a);
void	rrb(t_node **stack, int a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pile_down(t_node *stack, t_node *node);
void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b);

#endif
