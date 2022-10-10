/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:40:44 by jcauchet          #+#    #+#             */
/*   Updated: 2021/10/25 17:23:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*destination;
	int		i;

	source = (char *)src;
	destination = (char *)dst;
	i = 0;
	while (i < (int)n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
