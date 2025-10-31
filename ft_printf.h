/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:34:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 16:03:28 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef enum e_specifier{
	CHAR,
	STR,
	POINTER,
	DECIMAL,
	INTEGER,
	UN_DECIMAL,
	SMALL_HEX,
	BIG_HEX,
	PRECENT_SIGN
}t_specifier;

typedef struct s_format
{
	t_specifier	specifier;
}t_format;

int		ft_printf(const char	*str, ...);
char	*string_maker(va_list *ap);
char	*char_to_str(va_list *ap);
char	*convert_base(long num, char *base);

#endif
