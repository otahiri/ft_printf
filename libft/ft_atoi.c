/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:31:16 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 20:10:33 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	overflow_check(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*nptr && (*nptr == ' ' || ((*nptr <= '\r' && *nptr >= '\t'))))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		if (((num * 10) + (*nptr - '0')) < 0)
			return (overflow_check(sign));
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * sign);
}
