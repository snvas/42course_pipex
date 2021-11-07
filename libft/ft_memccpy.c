/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:46 by snovaes           #+#    #+#             */
/*   Updated: 2021/05/26 21:38:09 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{	
	size_t			i;
	unsigned char	*dest_c;
	unsigned char	*src_c;

	i = 0;
	src_c = (unsigned char *)src;
	dest_c = (unsigned char *)dest;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		if (src_c[i] == (unsigned char) c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
