/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freed_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:05:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/01 23:05:55 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freed_split(char *s, char c)
{
	char	**array;
	int		len;
	int		pos;
	int		i;
	int		count;

	count = word_count((char *)s, c);
	pos = 0;
	array = malloc ((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		len = word_len(pos, (char *)s, c);
		array[i] = malloc ((len + 1) * sizeof(char));
		if (!array[i])
			return (NULL);
		pos = ft_strncpy(array[i], pos, (char *)s, c);
		i++;
	}
	free(s);
	array[i] = NULL;
	return (array);
}
