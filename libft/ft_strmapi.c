/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:29:36 by jcauchet          #+#    #+#             */
/*   Updated: 2021/10/25 17:38:59 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i])
	{
		string[i] = f(i, (char)s[i]);
		i++;
	}
	string[i] = 0;
	return (string);
}
