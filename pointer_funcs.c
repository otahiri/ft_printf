/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:24:14 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:15:45 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*pointer_convert(va_list *ap)
{
	uintptr_t	ptr;
	char		*res;
	char		*tmp;

	tmp = convert_base(va_arg(*ap, long), "0123456789ABCDEF");
	res = ft_strjoin("0x", tmp);
	free(tmp);
	return (res);
}
