/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:38:33 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:02:07 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	switch_base(char *base, long num, int num_len, char *res)
{
	int	i;
	int	div;
	int	base_count;

	base_count = ft_strlen(base);
	div = 1;
	while (num_len > 1)
	{
		div *= base_count;
		num_len--;
	}
	i = 0;
	while (div > 0)
	{
		res[i] = base[(num / div)];
		num %= div;
		div /= base_count;
		i++;
	}
}

int	num_lenght(long num)
{
	int	count;

	count = 0;
	while (num > 9)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*convert_base(long num, char *base)
{
	char	*res;
	int		num_len;

	num_len = num_lenght(num);
	res = ft_calloc(num_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	switch_base(base, num, num_len, res);
	return (res);
}
