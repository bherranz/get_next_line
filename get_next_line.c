/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:46:25 by bherranz          #+#    #+#             */
/*   Updated: 2024/02/19 13:00:39 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *buffer)
{
	int		num_read;
	char	*new;

	num_read = 1;
	while (num_read > 0 && !ft_strchr(buffer, '\n'))
	{
		new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		num_read = read(fd, new, BUFFER_SIZE);
		if (num_read < 0)
		{
			if (buffer)
				free(buffer);
			free(new);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, new);
		free(new);
	}
	return (buffer);
}

char	*new_line(char *buffer)
{
	char	*line;
	int		count;

	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\n')
		count++;
	line = ft_substr(buffer, 0, count);
	return (line);
}

char	*to_be_continued(char *buffer, char *line)
{
	char	*new;
	int		start;

	start = 0;
	if (!buffer || !line)
		return (NULL);
	while (buffer[start] == line[start] && buffer[start])
		start++;
	new = ft_substr(buffer, start, ft_strlen(buffer) - start);
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		if (buffer)
			free(buffer);
		return (buffer = NULL, NULL);
	}
	line = new_line(buffer);
	buffer = to_be_continued(buffer, line);
	return (line);
}
