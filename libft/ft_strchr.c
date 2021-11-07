/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:46:27 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/02 20:45:10 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_u;
	unsigned char	c_u;

	s_u = (unsigned char *)s;
	c_u = (unsigned char)c;
	if (*s_u == c_u)
		return ((char *)s_u);
	while (*s_u++)
	{
		if (*s_u == c_u)
			return ((char *)s_u);
	}
	return (NULL);
}
