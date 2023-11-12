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
#include <stdio.h>


//TO DO = manage last line, clean stash, tester, clean everything
char *get_next_line(int fd)
{
	char *line;
	static char	*stash;
	line = NULL;
	stash = ft_strdup("");
	if (!BUFFER_SIZE)
		return ("YEA BOIII");
	read_buffer(fd, &stash);
	line = stash_to_line(stash, &line);
	//clean stash;
	return (line);
}


char	*stash_to_line(char *stash, char **line)
{
	int	i;
	int len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	len++;
	(*line) = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		(*line)[i] = stash[i];
		i++;
	}
	(*line)[i] = stash[i];
	(*line)[len] = 0;
	return ((*line));
}

int	check_stash(char **stash, int returned)
{
	int	i;

	i = 0;
	if(returned != BUFFER_SIZE)
		return (1);
	while ((*stash)[i])
	{
		i++;
		if ((*stash)[i] == '\n' || (*stash)[i] == 0)
			return (1);
	}
	return (0);
}

void	read_buffer(int fd, char **stash)
{
	int 		returned;
	char		*buffer;

	returned = BUFFER_SIZE;
	while (!check_stash(stash, returned))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[BUFFER_SIZE] = 0;
		returned = read(fd, buffer, BUFFER_SIZE);
		(*stash) = ft_strjoin(*(stash), buffer);
	}
}
