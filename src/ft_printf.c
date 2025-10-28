/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:40:25 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 09:47:19 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/ft_printf.h"
#include <__stdarg_va_list.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	find_conversion(const char *s, int idx, char *flags)
{
	char	*conversion_flags;
	int		j;
	int		i;

	conversion_flags = "cspdiuXx%";
	i = 0;
	while (s[i])
	{
		j = 0;
		while (conversion_flags[j])
		{
			if (s[i] == conversion_flags[j])
			{
				flags = malloc(sizeof(char) * (i + 1));
				if (!flags)
					return (0);
				ft_strlcpy(flags, s + idx, i);
				return (i);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_flags(char *flags, t_format *res_format)
{
	int	i;

	i = 0;
	while (flags[i] && flags[i] != '.')
	{
		if (flags[i] == '0')
		{
			if(!res_format->zero_padding)
				res_format->zero_padding = 1;
			i++;
		}
		else if (flags[i] == '-')
		{
			if(!res_format->printed_last)
				res_format->printed_last = 1;
			i++;
		}
		else if (flags[i] == '+')
		{
			if(!res_format->sign)
				res_format->sign = 1;
			i++;
		}
		else if (flags[i] == ' ')
		{
			if(!res_format->space)
				res_format->space = 1;
			i++;
		}
		else if (flags[i] == '#')
		{
			if(!res_format->prefix)
				res_format->prefix = 1;
			i++;
		}
		else
			return (-1);
	}
}

t_format *parse_string(char *flags, va_list *ap)
{
	t_format	*res_format;
	int	i;
	int	res;

	i = 0;
	res_format = (t_format *)malloc(sizeof(t_format));
	res = parse_flags(flags, res_format);
	if (res < 0)
	{
		write(1, flags, ft_strlen(flags));
		return (NULL);
	}
}

int print_var(const char *s, int idx, va_list *ap)
{
	char *flags;
	int	i;
	t_format	*res_format;

	i = find_conversion(s, idx,  flags);
	res_format = parse_string(flags, ap);
	if (!res_format)
		return (0);

	
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int	res;

	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			res = print_var(str, i, &ap);
		if (res)
			i += res;
		write(1, &str[i], 1);
		i++;
	}
}
