/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:47:00 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/07 15:47:00 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	read_buffer(int fd, char **stash);
int		check_stash(char *stash, int returned);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strlen(const char *s);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	stash_to_line(char *stash, char **line);
char	*clean_stash(char *stash);

#endif