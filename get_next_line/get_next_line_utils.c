/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:56:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/03/02 10:36:07 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*string;

	len = gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1;
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

int	gnl_ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_substr(char *s, int start, int len)
{
	char	*string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > gnl_ft_strlen(s))
		return (gnl_ft_strdup(""));
	if (gnl_ft_strlen(&s[start]) < len)
		len = gnl_ft_strlen(&s[start]);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = s[start];
		i++;
		start++;
	}
	string[i] = 0;
	return (string);
}

char	*gnl_ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
