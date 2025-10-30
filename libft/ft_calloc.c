/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:01:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 10:19:49 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			product;

	product = nmemb * size;
	if (size != 0 && product / size != nmemb)
		return (NULL);
	ptr = malloc(product);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, product);
	return (ptr);
}
