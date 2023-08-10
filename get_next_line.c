/* ************************************************************************** */
/*	                                                                         */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:10:57 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/17 14:13:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	modify_buffer(char *buffer)
{
	int	size = ft_strclen(buffer, '\n') + 1;
	int	total = ft_strlen(buffer) - size;
	int	i;

	i = 0;
	while (i < total && buffer[size])
		buffer[i++] = buffer[size++];
	buffer[i] = '\0';
}

char	*join_buffers(char *line, char *buf2)
{
	const int	size = ft_strclen(buf2, '\n') + 1;
	int			i;
	int			k;
	char		*new;

	i = 0;
	k = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buf2)) + 1);
	if (!new)
		return (NULL);
	while (line != NULL && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (buf2[k] && k < size)
		new[i++] = buf2[k++];
	new[i] = '\0';
	free(line);
	return (new);
}

char	*clear_buffer(char *buffer)
{
	int		size = ft_strclen(buffer, '\n') + 2;
	int		i;
	char	*new;

	i = 0;
	new = malloc(size * (sizeof(char)));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = buffer[i];
		i++;
	}
	new[size - 1] = '\0';
	return (new);
}

char	*read_file(char *buffer, char *line, int fd)
{
	int	bytes_read;

	bytes_read = 0;
	if (buffer[0] != '\0')
		line = clear_buffer(buffer);
	while (!search_char(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		line = join_buffers(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line = read_file(buffer, line, fd);
	if (line == NULL || line[0] == '\0')
		return (NULL);
	modify_buffer(buffer);
	return (line);
}
