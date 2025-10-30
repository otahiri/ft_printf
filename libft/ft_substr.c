/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:25:44 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/22 10:19:01 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	end;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > ft_strlen(s))
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	end = start + len;
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
