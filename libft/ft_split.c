/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:10:25 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/01 23:04:59 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char *s, char c)
{
	int	init;
	int	i;
	int	word_count;

	init = 0;
	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			init = 0;
		else if (!init)
		{
			init = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

int	word_len(int pos, char *s, char c)
{
	int	i;

	i = 0;
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
	{
		i++;
		pos++;
	}
	return (i);
}

int	ft_strncpy(char *array, int pos, char *s, char c)
{
	int	i;

	i = 0;
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
	{
		array[i] = s[pos];
		i++;
		pos++;
	}
	array[i] = '\0';
	return (pos);
}

char	**ft_split(char *s, char c)
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
	array[i] = NULL;
	return (array);
}
