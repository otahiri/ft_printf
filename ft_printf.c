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

static int	print_percent(char *spec, t_format *format)
{
	if (spec[1] != '%')
	{
		free(format);
		free(spec);
		return (-1);
	}
	free(format);
	ft_putchar_fd('%', 1);
	return (1);
}

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
	t_format		*format;
	char			*res;
	int				ret;
	static char		*(*func_arr[9])(va_list *ap) = {char_to_str, string_maker,
		pointer_convert, from_decimal_to_str, from_int_to_str,
		from_uint_to_str, from_int_to_hex, from_int_to_bhex};

	format = ft_calloc(1, sizeof(t_format));
	if (!format)
		return (-1);
	format->specifier = is_specifier(con_spec[ft_strlen(con_spec) - 1]);
	if (format->specifier == 8)
		return (print_percent(con_spec, format));
	res = func_arr[format->specifier](ap);
	if (!res)
	{
		free(format);
		return (-1);
	}
	ft_putstr_fd(res, 1);
	ret = ft_strlen(res) + (format->specifier == 0 && res[0] == '\0');
	free(format);
	free(res);
	return (ret);
}

int	set_flags_string(int *res, char const *str, va_list *ap)
{
	int		len;
	char	*conv_spec;
	int		tmp;
	int		ret;

	len = 1;
	while (str[len] && !ft_isalpha(str[len]) && str[len] != '%')
		len++;
	conv_spec = ft_substr(str, 0, len + 1);
	if (!conv_spec)
		return (0);
	if (is_specifier(str[len]) < 0)
	{
		free(conv_spec);
		return (-1);
	}
	tmp = parse_conver_specifier(conv_spec, ap);
	if (tmp < 0)
		return (-1);
	*res += tmp;
	ret = ft_strlen(conv_spec);
	free(conv_spec);
	return (ret);
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	ap;
	int		res;
	int		tmp;

	if (!str)
		return (-1);
	i = 0;
	va_start(ap, str);
	res = 0;
	while (str[i])
	{
		tmp = 0;
		if (str[i] == '%')
			tmp = set_flags_string(&res, str + i, &ap);
		if (tmp < 0)
			return (-1);
		i += tmp;
		if (!str[i])
			break ;
		if (tmp == 0)
			res += write(1, &str[i++], 1);
	}
	va_end(ap);
	return (res);
}
