/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:47:03 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/07 15:47:03 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char 	*is_eol(char *str)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (i == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char *line;
	char *buffer;

	line = NULL;
	if(fd < 0 || read(fd, line, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd);
	line =ft_strjoin(line, buffer);
	free(buffer);
	return (line);

}



char	*read_buffer(int fd)
{
	char *buffer;
	int is_end;
	char *line;

	is_end = 1;
	while(is_end)
	{
		buffer = malloc(sizeof(char) * 6);
		read (fd, buffer, 5);
		printf("%s", buffer);
		buffer[5] = 0;
		line = ft_strcat(line, buffer);
	}
	return (line);
}
