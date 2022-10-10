/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:44:09 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/14 11:47:08 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_size(char	**array)
{
	int	len;

	len = 0;
	if (!array)
		return (0);
	while (array[len])
		len++;
	return (len);
}
