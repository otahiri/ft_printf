/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:15:53 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:52 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	idx;
	int	count;
	int	len;

	count = 0;
	idx = 0;
	while (s[idx])
	{
		len = 0;
		while (s[idx + len] && s[idx + len] != c)
			len++;
		if (len)
		{
			count++;
			idx += len;
		}
		if (s[idx])
			idx++;
	}
	return (count);
}

static char	*word_copy(char *res, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i++] = *src;
		src++;
	}
	res[i] = '\0';
	return (res);
}

static void	free_all(char **res, int last_elem)
{
	int	i;

	i = 0;
	while (i < last_elem)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static void	spliter(char const *s, char c, char **res)
{
	int	idx;
	int	len;

	idx = 0;
	while (*s)
	{
		len = 0;
		while (*(s + len) && *(s + len) != c)
			len++;
		if (len > 0)
		{
			res[idx] = malloc(sizeof(char) * (len + 1));
			if (!res[idx])
			{
				free_all(res, idx);
				return ;
			}
			res[idx] = word_copy(res[idx], s, len);
			s += len;
			idx++;
		}
		if (*s)
			s++;
	}
	res[idx] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	spliter(s, c, res);
	return (res);
}
