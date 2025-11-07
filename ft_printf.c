/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:30:55 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/03 11:04:23 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	is_specifier(char c)
{
	int		i;
	char	*specif;

	specif = "cspdiuxX%";
	i = 0;
	while (specif[i])
	{
		if (c == specif[i])
			return (i);
		i++;
	}
	return (-1);
}

int	parse_percent(const char *str, va_list *ap)
{
	static int	(*func_arr[8])(va_list *ap) = {print_char, print_str,
		print_pointer, print_decimal, print_int,
		print_uint, print_hex, print_big_hex};
	int			func_idx;

	func_idx = is_specifier(str[1]);
	if (func_idx < 0)
		return (-1);
	else if (func_idx == 8)
		return (write(1, "%", 1));
	else
		return (func_arr[func_idx](ap));
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	ap;
	int		res;
	int		tmp;

	if (!str || write(1, NULL, 0) < 0)
		return (-1);
	i = 0;
	va_start(ap, str);
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = parse_percent(str + i, &ap);
			if (tmp < 0)
				return (-1);
			res += tmp;
			i += 2;
			continue ;
		}
		res += write(1, &str[i++], 1);
	}
	va_end(ap);
	return (res);
}
