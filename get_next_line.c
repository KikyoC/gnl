/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:04 by tom               #+#    #+#             */
/*   Updated: 2024/10/20 14:40:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*readfile(int fd, char *res)
{
    ssize_t	bytes;
	char	*buffer;
	char	*tmp;
	
	bytes = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = 0;
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, buffer);
		free(buffer);
		free(tmp);
		if (ft_strchr(res, '\n'))
			break ;
	}
	return (res);
}
char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	j = 0;
	while (buffer[i + 1])
	{
		res[j] = buffer[i + 1];
		i++;
		j++;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <=0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*tmp;
	
	fd = open("text.txt", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	// char	*buffer;
	// char	*line;
	
	// if (fd < 0 || BUFFER_SIZE <=0 || read(fd, 0, 0) < 0)
	// 	return (0);
	// buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// buffer = readfile(fd, buffer);
	// if (!buffer)
	// 	return (0);
	// line = ft_getline(buffer);
	// printf("%s", line);
	close(fd);
}