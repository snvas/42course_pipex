/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:21:29 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/12 02:16:57 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*s;
	size_t			n;

	n = nmemb * size;
	s = malloc(n);
	if (s == 0)
		return (0);
	return (ft_memset(s, 0, n));
}
