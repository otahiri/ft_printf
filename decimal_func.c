/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:55:14 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/01 11:59:32 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*from_decimal_to_str(va_list ap)
{
	int		num;
	char	*res;

	num = va_arg(ap, int);
	res = ft_itoa(num);
	return (res);
}
