/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_uint_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:57:01 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/01 12:59:10 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	num_len_counter(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*array_filler(unsigned int num)
{
	int		i;
	int		j;
	char	tmp;
	char	*res;

	i = 0;
	j = 0;
	res = ft_calloc(num_len_counter(num) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (num > 0)
	{
		res[i++] = (num % 10) + '0';
		num /= 10;
	}
	i--;
	while (i >= j)
	{
		tmp = res[i];
		res[i--] = res[j];
		res[j++] = tmp;
	}
	return (res);
}

static char	*ft_uitoa(unsigned int num)
{
	char	*res;

	if (num == 0)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		return (res);
	}
	res = array_filler(num);
	return (res);
}

char	*from_uint_to_str(va_list *ap)
{
	unsigned int	num;
	char			*res;

	num = va_arg(*ap, unsigned int);
	res = ft_uitoa(num);
	return (res);
}
