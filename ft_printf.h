/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:34:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/02 11:58:22 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
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
	int			error;
	int			minus;
	int			zero;
	int			precision;
	int			hashtag;
	int			space;
	int			plus;
	int			width;
}t_format;

int			ft_printf(const char	*str, ...);
char		*string_maker(va_list *ap);
char		*char_to_str(va_list *ap);
char		*convert_base(unsigned long num, char *base);
char		*pointer_convert(va_list *ap);
char		*from_decimal_to_str(va_list *ap);
char		*from_int_to_str(va_list *ap);
char		*from_uint_to_str(va_list *ap);
char		*from_int_to_hex(va_list *ap);
char		*from_int_to_bhex(va_list *ap);
t_format	*set_flags(t_format *format, char *conv_spec, va_list *ap);
char		*set_bonus(t_format *format, char *res, \
		va_list *ap, char *con_spec);

#endif
