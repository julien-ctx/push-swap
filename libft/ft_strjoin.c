/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:57:27 by juliencauch       #+#    #+#             */
/*   Updated: 2022/01/26 22:08:57 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*string;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	if (s1)
		while (s1[j])
			string[i++] = s1[j++];
	j = 0;
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	return (string);
}
