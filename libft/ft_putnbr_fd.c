/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:48:02 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/22 11:36:09 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	convert_num(size_t idx, long num, char res[])
{
	size_t	i;
	char	tmp;
	size_t	output;
	int		j;

	i = 0;
	if (res[0] == '-')
		i++;
	while (num > 0)
	{
		res[idx++] = (num % 10) + '0';
		num /= 10;
	}
	output = idx;
	if (output == 1)
		return (output);
	j = idx - 1;
	while (j > (int)i)
	{
		tmp = res[i];
		res[i++] = res[j];
		res[j--] = tmp;
	}
	return (output);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	num[32];
	long	tmp_num;

	i = 0;
	tmp_num = n;
	if (tmp_num < 0)
	{
		tmp_num *= -1;
		num[i++] = '-';
	}
	if (tmp_num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = convert_num(i, tmp_num, num);
	write(fd, num, i);
}
