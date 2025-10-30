/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:30:55 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:15:42 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"
#include <__stdarg_va_list.h>

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

int	parse_conver_specifier(char *con_spec, va_list *ap)
{
	t_format	*format;
	char		*res;
	char		*(*func_arr)(va_list *ap);

	ft_bzero(format, sizeof(t_format));

	format->specifier = is_specifier(con_spec[ft_strlen(con_spec) - 1]);

	return (0);
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	ap;
	char	*conv_specifier;
	int		res;
	int		len;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (is_specifier(str[i]) >= 0)
				len++;
			conv_specifier = ft_substr(str, i, i + len);
			if (!conv_specifier)
				return (0);
			i += ft_strlen(conv_specifier);
			res += parse_conver_specifier(conv_specifier, &ap);
		}
		write(1, &str[i], 1);
		res++;
		i++;
	}
	write(1, "\n", 1);
	return (res);
}
