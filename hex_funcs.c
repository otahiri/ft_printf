/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:38:57 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/01 14:42:10 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*from_int_to_hex(va_list *ap)
{
	unsigned int	num;
	char			*res;

	num = va_arg(*ap, unsigned int);
	res = convert_base((unsigned long)num, "0123456789abcdef");
	return (res);
}
