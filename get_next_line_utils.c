/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:39 by mbuchs            #+#    #+#             */
/*   Updated: 2023/11/09 18:22:41 by mbuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*array;
	int		lenght;

	array = NULL;
	if (!s1 || !s2)
		return (NULL);
	lenght = (ft_strlen((char *)s1)) + (ft_strlen((char *)s2) + 1);
	array = ft_calloc(lenght, sizeof(char));
	if (array == NULL)
		return (NULL);
	array[lenght] = 0;
	ft_strcat(array, (char *)s1);
	free(s1);
	ft_strcat(array, (char *)s2);
	free(s2);
	return (array);
}

char	*ft_strdup(const char *s)
{
	char	*tab;

	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (tab);
	ft_strcpy(tab, s);
	return (tab);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if ((long long)size == 0 || (long long)nmemb == 0)
		return (malloc(1));
	if ((long long)size < 0 || (long long)nmemb < 0)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, '\0', n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pos;

	if (!s)
		return (NULL);
	pos = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		(*pos) = c;
		pos++;
		i++;
	}
	return (s);
}
