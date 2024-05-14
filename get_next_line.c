/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:18:17 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/14 19:28:16 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

static char	*read_file(int fd, char *buf)
{
	char	*buffer;
	int		count_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
/* 	if (!buffer)
	    return (free(buffer), buffer = NULL); */
	count_read = 1;
	while ((count_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (count_read == -1)
			return (free(buffer), buffer = NULL);
		if (count_read == 0)
			break ;
		buffer[count_read] = '\0';
		buf = ft_join(buf, buffer);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (free(line), line = NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n';
	return (line);
}

static char	*ft_left_over(char *buffer)
{
	int		i;
	int		j;
	char	*left_over;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL);
	left_over = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if (!left_over)
		return (free(left_over), left_over = NULL);
	i++;
	j = 0;
	while (buffer[i])
		left_over[j++] = buffer[i++];
	free(buffer);
	return (left_over);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(left_over), left_over = NULL);
	left_over = read_file(fd, left_over);
	if (!left_over)
		return (free(left_over), left_over = NULL);
	line = ft_line(left_over);
	left_over = ft_left_over(left_over);
	return (line);
}
