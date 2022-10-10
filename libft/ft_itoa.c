/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:08:49 by jcauchet          #+#    #+#             */
/*   Updated: 2021/10/25 17:14:34 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nb;

	len = nb_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	else if (nb == 0)
		str[0] = 48;
	while (nb)
	{
		str[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
