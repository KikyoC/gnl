/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:02 by tom               #+#    #+#             */
/*   Updated: 2024/10/19 20:09:18 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > (size_t) - 1 / size)
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}