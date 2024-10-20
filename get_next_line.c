/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:04 by tom               #+#    #+#             */
/*   Updated: 2024/10/19 21:12:05 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_line(int fd, char *buffer)
{
	return (read(fd, buffer, BUFFER_SIZE));
	
}

char    *get_next_line(int fd)
{
    int		i;
    char	*buffer;
    char	*result;

    if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    i = 0;
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	    
}