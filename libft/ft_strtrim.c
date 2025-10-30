/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:02:12 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/22 09:47:25 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_trim(char const *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start && is_trim(set, *start))
		start++;
	end = (char *)s1 + ft_strlen(s1);
	while (end > start && is_trim(set, *(end - 1)))
		end--;
	if (start >= end)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * ((end - start) + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, start, (end - start) + 1);
	return (res);
}
