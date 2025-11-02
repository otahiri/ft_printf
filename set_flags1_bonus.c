/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:06:09 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/02 11:50:24 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	is_flag(char c)
{
	char	*flags;
	int		i;

	flags = "-0# +";
	i = 0;
	while (flags[i])
	{
		if (c == flags[i])
			return (i);
		i++;
	}
	return (0);
}

int	set_zero(t_format *format, char *conv_spec)
{
	int	i;

	i = 0;
	format->zero = 1;
	format->zero += ft_atoi(conv_spec + i);
	while (conv_spec[i] && ft_isdigit(conv_spec[i]))
		i++;
	return (i);
}

void	set_percision_width(t_format *format, char *conv_spec, va_list *ap)
{
	int	i;

	i = 0;
	if (conv_spec[i] && conv_spec[i] == '.')
		format->precision = 1;
	i++;
	if (conv_spec[i] && !ft_isalnum(conv_spec[i]) && conv_spec[i] != '*')
	{
		format->error = 1;
		return ;
	}
	if (conv_spec[i] == '*')
		format->width = va_arg(*ap, int);
	format->width += ft_atoi(conv_spec + i);
	while (ft_isdigit(conv_spec[i]))
		i++;
	if (!ft_isalpha(conv_spec[i]))
	{
		format->error = 1;
		return ;
	}
}

t_format	*set_flags(t_format *format, char *conv_spec, va_list *ap)
{
	int	i;

	i = 0;
	while (conv_spec[i] && conv_spec[i] != '.')
	{
		if (!is_flag(conv_spec[i]))
		{
			format->error = 1;
			return (format);
		}
		else if (conv_spec[i] == '-')
			format->minus = 1;
		else if (conv_spec[i] == '0')
			i += set_zero(format, conv_spec + i);
		else if (conv_spec[i] == '#')
			format->hashtag = 1;
		else if (conv_spec[i] == ' ')
			format->space = 1;
		else if (conv_spec[i] == '+')
			format->plus = 1;
		else if (ft_isdigit(conv_spec[i]))
			break ;
	}
	set_percision_width(format, conv_spec, ap);
	return (format);
}
