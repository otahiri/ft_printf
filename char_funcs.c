/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:00:25 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:03:40 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*char_to_str(va_list *ap)
{
	char	*res;
	char	c;

	res = malloc(sizeof(char) * 2);
	c = (unsigned char)va_arg(*ap, int);
	if (!res)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}
