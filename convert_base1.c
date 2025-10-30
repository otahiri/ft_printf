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

int	num_lenght(long num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*convert_base(long num, char *base)
{
	int		base_count;
	char	*res;

	res = ft_calloc(num_lenght(num) + 1, sizeof(char));
	if (!res)
		return (NULL);
	base_count = ft_strlen(base);
	res = 
}
