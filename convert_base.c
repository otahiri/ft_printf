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

void	switch_base(char *base, unsigned long num, int num_len, char *res)
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

int	num_lenght(unsigned long num, int base_len)
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

	num_len = num_lenght(num, ft_strlen(base));
	res = ft_calloc(num_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	switch_base(base, num, num_len, res);
	return (res);
}
