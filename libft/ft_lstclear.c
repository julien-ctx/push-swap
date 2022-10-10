/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:01:06 by juliencauch       #+#    #+#             */
/*   Updated: 2021/10/25 17:16:55 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	list = *lst;
	if (!list)
		return ;
	while (list)
	{
		ft_lstdelone(list, del);
		list = list->next;
	}
	*lst = NULL;
}
