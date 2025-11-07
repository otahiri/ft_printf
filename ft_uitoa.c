/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:49:35 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/06 09:51:52 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	rev_str(char *s, int last_idx)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < last_idx)
	{
		tmp = s[last_idx];
		s[last_idx] = s[i];
		s[i] = tmp;
		i++;
		last_idx--;
	}
}

static int	size_count(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	my_put_nbr(char *res, int idx, long num)
{
	if (num == 0)
		res[idx++] = '0';
	while (num > 0)
	{
		res[idx++] = (num % 10) + '0';
		num /= 10;
	}
	res[idx] = '\0';
	return (idx);
}

char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*res;
	long	num;

	num = n;
	size = size_count(num);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	size = 0;
	size = my_put_nbr(res, size, num);
	rev_str(res, size - 1);
	return (res);
}
