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
	unsigned long	ptr;
	char			*res;
	char			*tmp;

	ptr = va_arg(*ap, unsigned long);
	if (!ptr)
		return (ft_strdup("(nil)"));
	tmp = convert_base(ptr, "0123456789abcdef");
	res = ft_strjoin("0x", tmp);
	free(tmp);
	return (res);
}
