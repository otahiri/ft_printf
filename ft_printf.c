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
	char		*(*func_arr[9])(va_list *ap);
	int			len;

	format = ft_calloc(1, sizeof(t_format));
	ft_bzero(format, sizeof(t_format));
	format->specifier = is_specifier(con_spec[ft_strlen(con_spec) - 1]);
	func_arr[0] = &char_to_str;
	func_arr[1] = &string_maker;
	func_arr[2] = &pointer_convert;
	res = func_arr[format->specifier](ap);
	len = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}

int	set_flags_string(int *res, char const *str, va_list *ap)
{
	int		len;
	char	*conv_spec;

	len = 1;
	while (str[len] && is_specifier(str[len]) < 0)
		len++;
	conv_spec = ft_substr(str, 0, len + 1);
	if (!conv_spec)
		return (0);
	res += parse_conver_specifier(conv_spec, ap);
	return (ft_strlen(conv_spec));
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	ap;
	int		res;

	i = 0;
	va_start(ap, str);
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += set_flags_string(&res, str + i, &ap);
		write(1, &str[i], 1);
		res++;
		i++;
	}
	va_end(ap);
	return (res);
}
