/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:16 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 22:27:45 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*extract_line(char **reminder)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*reminder)[i] != '\0' && (*reminder)[i] != '\n')
		i++;
	temp = *reminder;
	line = ft_substr(temp, 0, i + 1);
	*reminder = ft_strdup(&(*reminder)[i + 1]);
	free_ptr(&temp);
	return (line);
}

static int	read_file(int fd, char **buffer, char **reminder)
{
	int		size;
	char	*temp;

	size = 1;
	while (!ft_strchr(*reminder, '\n') && size)
	{
		size = read(fd, *buffer, BUFFER_SIZE);
		if (size == -1)
			return (size);
		(*buffer)[size] = '\0';
		temp = *reminder;
		*reminder = ft_strjoin(temp, *buffer);
		free_ptr(&temp);
	}
	return (size);
}

static char	*get_line(int fd, char **buffer, char **reminder)
{
	int		size;
	char	*temp;

	if (ft_strchr(*reminder, '\n'))
		return (extract_line(reminder));
	size = read_file(fd, buffer, reminder);
	if ((size == 0 || size == -1) && !**reminder)
	{
		free_ptr(reminder);
		return (NULL);
	}
	if (ft_strchr(*reminder, '\n'))
		return (extract_line(reminder));
	if (!ft_strchr(*reminder, '\n') && **reminder)
	{
		temp = ft_strdup(*reminder);
		free_ptr(reminder);
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*reminder[OPEN_MAX + 1];
	char			*buffer;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!reminder[fd])
		reminder[fd] = ft_strdup("");
	result = get_line(fd, &buffer, &reminder[fd]);
	free_ptr(&buffer);
	return (result);
}
