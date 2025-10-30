/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:36:53 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 12:51:35 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	len;
	size_t	temp_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	len = 0;
	temp_len = 0;
	res_str = malloc(sizeof(char) * (total_len + 1));
	if (!res_str)
		return (NULL);
	while (s1[temp_len])
		res_str[len++] = s1[temp_len++];
	temp_len = 0;
	while (len < total_len)
		res_str[len++] = s2[temp_len++];
	res_str[len] = '\0';
	return (res_str);
}
