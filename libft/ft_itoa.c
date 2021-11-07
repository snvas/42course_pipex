/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:53 by snovaes           #+#    #+#             */
/*   Updated: 2021/05/29 17:41:26 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_nbr_str(char *str, int n, size_t size)
{
	str[size] = '\0';
	if (n >= 0)
	{
		while (size--)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		while (--size)
		{
			str[size] = (n % 10) * -1 + '0';
			n /= 10;
		}
		str[size] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		temp;
	char	*num;
	size_t	size;

	if (n >= 0)
		size = 1;
	else
		size = 2;
	temp = n / 10;
	while (temp)
	{
		size++;
		temp /= 10;
	}
	num = malloc(size + 1);
	if (num == NULL)
		return (NULL);
	get_nbr_str(num, n, size);
	return (num);
}
