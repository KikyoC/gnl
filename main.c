/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:10:24 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/22 11:29:47 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	char	*tmp;
// 	int		fd;

// 	fd = open("read_error.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	tmp = get_next_line(fd);
// 	if (!tmp)
// 		printf("NULL\n");
// 	while (tmp)
// 	{
// 		printf("%s", tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	printf("%d\n", fd);
// 	close(fd);
// }

#include <stdio.h>
int main ()
{
    const char    *PATH = "text.txt";
    int            fd = open(PATH, O_RDONLY);
    char        *line =  get_next_line(fd);
    int            i = 0;

    while (i <= 10)
    {
        printf("ligne %d --> %s", i, line);
        free(line);    
        line = get_next_line(fd);
        i++;
    }
    free(line);
}
