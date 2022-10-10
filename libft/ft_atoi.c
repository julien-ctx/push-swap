/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:12:55 by jcauchet          #+#    #+#             */
/*   Updated: 2022/03/07 14:24:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	if ((str[i - 1] == '-' || str[i - 1] == '+') && !str[i])
		error();
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			error();
		else
			result = result * 10 + str[i++] - '0';
	}
	if ((sign * result < -2147483648) || (sign * result > 2147483647))
		error();
	return (sign * result);
}
