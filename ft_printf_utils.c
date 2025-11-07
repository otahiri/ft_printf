/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:37:53 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/06 10:45:23 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	return (write(1, &c, 1));
}

int	print_str(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_uint(va_list *ap)
{
	unsigned int	num;
	char			*res;
	int				ret;

	num = va_arg(*ap, unsigned int);
	res = ft_uitoa(num);
	if (!res)
		return (-1);
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}

int	print_int(va_list *ap)
{
	int		num;
	char	*res;
	int		ret;

	num = va_arg(*ap, int);
	res = ft_itoa(num);
	if (!res)
		return (-1);
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}

int	print_decimal(va_list *ap)
{
	int		num;
	char	*res;
	int		ret;

	num = va_arg(*ap, unsigned int);
	res = ft_itoa(num);
	if (!res)
		return (-1);
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}
