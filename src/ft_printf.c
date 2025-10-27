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

t_format parse_string(char *flags, va_list *ap)
{
	t_format	*res_format;
	int	i;

	i = 0;
	res_format = (t_format *)malloc(sizeof(t_format));
	while (flags[i])
	{
		if (!res_format->zero_padding && flags[i] == '0')
			res_format->zero_padding = ft_atoi(flags + i);
	}
}

typedef struct s_format
{
	void			*content;
	int				printed_last;
	int				sign;
	int				prefix;
	int				precision;
	int				zero_padding;
	int				width;
	t_conversion	conversion;
}t_format;
int print_var(const char *s, int idx, va_list *ap)
{
	char *flags;
	int	i;
	t_format	res_format;

	i = find_conversion(s, idx,  flags);
	res_format = parse_string(flags, &ap);

	
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			print_var(str, i);
		write(1, &str[i], 1);
	}
}
