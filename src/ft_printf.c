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

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		res;

	va_start(ap, str);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
