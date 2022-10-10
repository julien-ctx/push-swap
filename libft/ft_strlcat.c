/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:01:37 by jcauchet          #+#    #+#             */
/*   Updated: 2021/10/25 17:36:19 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	len = ft_strlen(src)+ ft_strlen(dst);
	while (src[j] && i < dstsize - 1)
		dst[i++] = (char)src[j++];
	dst[i] = 0;
	return (len);
}

/*int main (int ac, char **av)
{
	char dst[5] = "aaaa";
	char src[10] = "Hello";
	printf("%lu\n", strlcat(dst, src, 5));
	printf("%s\n", dst);

}*/
