/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:12:04 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/06 10:45:24 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_pointer(va_list *ap)
{
	char			*hex;
	char			*res;
	int				ret;
	unsigned long	num;

	num = va_arg(*ap, unsigned long);
	if (num == 0)
		return (write(1, "(nil)", 5));
	hex = convert_base(num, "0123456789abcdef");
	if (!hex)
		return (-1);
	res = ft_strjoin("0x", hex);
	if (!res)
	{
		free(hex);
		return (-1);
	}
	ret = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	free(hex);
	return (ret);
}

int	print_hex(va_list *ap)
{
	char			*res;
	unsigned int	num;
	int				ret;

	num = va_arg(*ap, unsigned int);
	res = convert_base(num, "0123456789abcdef");
	if (!res)
		return (-1);
	ret = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}

int	print_big_hex(va_list *ap)
{
	char			*res;
	unsigned int	num;
	int				ret;

	num = va_arg(*ap, unsigned int);
	res = convert_base(num, "0123456789ABCDEF");
	if (!res)
		return (-1);
	ret = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}
