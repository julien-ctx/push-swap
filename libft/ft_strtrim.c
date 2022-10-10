/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:15:57 by juliencauch       #+#    #+#             */
/*   Updated: 2021/10/25 17:40:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	*string;

	i = 0;
	j = 0;
	count = ft_strlen(s1) - 1;
	while (ft_strchr(set, (int)s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, (int)s1[count]) && count-- >= 0)
		i++;
	count = ft_strlen(s1) - i;
	if (count == (int)ft_strlen(s1) * (-1))
		return (ft_strdup(""));
	string = malloc ((count + 1) * sizeof(char));
	if (!string || !s1)
		return (NULL);
	i = 0;
	while (ft_strchr(set, (int)s1[i]) && s1[i])
		i++;
	while (j < count)
		string[j++] = (char)s1[i++];
	string[j] = 0;
	return (string);
}
