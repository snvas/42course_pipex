/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:10:18 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/02 19:55:50 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//com leak de memoria
#include "libft.h"
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	if 
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	m_size;
	size_t	s_start;

	if (s == NULL)
		return (NULL);
	s_start = start;
	size = ft_strlen(s);
	if (start > size)
	{
		m_size = 1;
		s_start = 0;
	}
	else if (start + len > size)
		m_size = size - start + 1;
	else
		m_size = len + 1;
	sub = malloc(m_size);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + s_start, m_size);
	return (sub);
}
