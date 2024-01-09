/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:43:39 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:35:24 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isthere(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, int size)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < size)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char **s1, char const *s2, int i)
{
	char	*p;
	int		j1;

	if (!*s1 && !s2)
		return (NULL);
	if (!s2)
		return (NULL);
	j1 = ft_strlen(*s1);
	p = malloc(j1 + i + 1);
	if (!p)
		return (free(*s1), NULL);
	ft_memcpy(p, *s1, j1);
	ft_memcpy(p + j1, s2, i);
	p[j1 + i] = '\0';
	free(*s1);
	return (p);
}
