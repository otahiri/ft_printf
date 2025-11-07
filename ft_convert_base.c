/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:10:50 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/06 10:11:02 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	switch_base(char *base, unsigned long num, char *res)
{
	int		i;
	int		j;
	int		base_count;
	char	tmp;

	i = 0;
	j = 0;
	base_count = ft_strlen(base);
	while (num > 0)
	{
		res[i++] = base[num % base_count];
		num /= base_count;
	}
	i--;
	while (j <= i)
	{
		tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
		i--;
		j++;
	}
}

static int	num_lenght(unsigned long num, int base_len)
{
	int	count;

	count = 0;
	while (num >= (unsigned long)base_len)
	{
		num /= base_len;
		count++;
	}
	return (count);
}

char	*convert_base(unsigned long num, char *base)
{
	char	*res;
	int		num_len;

	if (num == 0)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		return (res);
	}
	num_len = num_lenght(num, ft_strlen(base));
	res = ft_calloc(num_len + 2, sizeof(char));
	if (!res)
		return (NULL);
	switch_base(base, num, res);
	return (res);
}
