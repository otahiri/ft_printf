/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:07:46 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:03:37 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_maker(va_list *ap)
{
	char	*res;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	res = ft_strdup(str);
	return (res);
}
