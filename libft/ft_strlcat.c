/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:31:04 by snovaes           #+#    #+#             */
/*   Updated: 2021/05/22 16:58:43 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_dest_len(char *dest, size_t size)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_size;

	j = 0;
	i = ft_dest_len(dest, size);
	src_size = ft_strlen(src);
	if (i < size)
	{
		while (i + j < size - 1 && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (i + src_size);
}
