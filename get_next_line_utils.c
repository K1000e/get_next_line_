/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:21:37 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/12 18:45:21 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)(s));
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, (count * size));
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		size;

	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	res = ft_calloc(sizeof(char), (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (*s2)
			res[i++] = *s2++;
	return (res);
}
