/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:17:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/02 11:57:11 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*apply_flags(t_format *format, char *res)
{
	static char		*(*func_arr[9])(va_list *ap) = {};

	if (format->error)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*set_bonus(t_format *format, char *res, va_list *ap, char *con_spec)
{
	format = set_flags(format, con_spec, ap);
	res = apply_flags(format, res);
	return (res);
}
