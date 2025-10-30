/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:25:30 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 14:39:40 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tdest;
	unsigned char	*tsrc;

	tdest = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}
