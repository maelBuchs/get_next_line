/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:33:07 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/08 22:33:07 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static char	*stash;
	line = NULL;
	stash = ft_strdup("");
	if (!BUFFER_SIZE)
		return ("YEA BOIII");
	read_buffer(fd, stash);

	(void) line;
	//line = stash_to_line(fd);
	return (stash);
}


// char	*stash_to_line(int fd)
// {


// 	return (line);
// }

int	check_stash(char *stash, int returned)
{
	int	i;

	i = 0;
	if(returned != BUFFER_SIZE)
		return (1);
	while (stash[i])
	{
		i++;
		if (stash[i] == '\n' || stash[i] == 0)
			return (1);
	}
	return (0);
}

char	*read_buffer(int fd, char *stash)
{
	char		*line;
	int 		returned;
	char		*buffer;

	(void) line;
	returned = BUFFER_SIZE;
	while (!check_stash(stash, returned))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[BUFFER_SIZE] = 0;
		returned = read(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}
