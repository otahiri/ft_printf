/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:28:43 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/24 12:13:44 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_conversion {
	CHAR,
	STR,
	VOID,
	DECIMAL,
	INT,
	UINT,
	UDECIMAL,
	LOWER_HEX,
	UPPER_HEX,
	PRECENT_SIGN
}t_conversion;

typedef struct s_format
{
	void			*content;
	int				printed_last;
	int				sign;
	int				prefix;
	int				precision;
	int				zero_padding;
	int				width;
	int				space;
	t_conversion	conversion;
}t_format;

#endif
