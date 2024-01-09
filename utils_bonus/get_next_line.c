/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:22:40 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:35:38 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*re_load_str(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (*str && *str != '\n')
	{
		i++;
		str++;
	}
	if (*str == '\n')
		str++;
	res = malloc(j - i);
	if (!res)
		return (NULL);
	res[j - i - 1] = '\0';
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	*re_load_p(char **str)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (*(*str + i) && *(*str + i) != '\n')
		i++;
	if (*(*str + i) == '\n')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (free(*str), NULL);
	p[i--] = '\0';
	while (i >= 0)
	{
		p[i] = *(*str + i);
		i--;
	}
	free(*str);
	return (p);
}

char	*ver_line(int i, char **p, char **b, char **str)
{
	if (i == -1)
		return (free(*b), free(*str), *str = NULL, NULL);
	else
	{
		if (!*p)
			return (free(*p), free(*b), free(*str), *str = NULL, NULL);
		else
		{
			if (ft_isthere(*p))
				*str = re_load_str(*p);
			else
			{
				free(*str);
				*str = NULL;
				if (!**p)
					return (free(*b), free(*p), NULL);
			}
			*p = re_load_p(p);
			if (!*p)
				return (free(*b), free(*str), *str = NULL, NULL);
			return (free(*b), *p);
		}
	}
}

char	*loading_line(int t[], char **p, char **b, char **str)
{
	while (t[0] && !ft_isthere(*b))
	{
		t[0] = read(t[1], *b, 1);
		*(*b + t[0]) = '\0';
		*p = ft_strjoin(p, *b, t[0]);
		if (!*p)
			return (free(*b), free(*str), *str = NULL, NULL);
	}
	if (ft_isthere(*p))
		*str = re_load_str(*p);
	else
	{
		free(*str);
		*str = NULL;
	}
	*p = re_load_p(p);
	if (!*p)
		return (free(*b), free(*str), *str = NULL, NULL);
	return (free(*b), *p);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*b;
	char		*p;
	int			t[2];

	b = NULL;
	p = NULL;
	t[0] = 0;
	t[1] = fd;
	if (read(fd, 0, 0) == -1 || 1 <= 0)
		return (free(str), str = NULL, NULL);
	b = malloc((size_t)1 + 1);
	if (!b)
		return (free(str), str = NULL, NULL);
	p = ft_strjoin(&p, str, ft_strlen(str));
	free(str);
	str = NULL;
	t[0] = read(fd, b, 1);
	if (!t[0] || t[0] == -1)
		return (ver_line(t[0], &p, &b, &str));
	b[t[0]] = '\0';
	p = ft_strjoin(&p, b, t[0]);
	if (!p)
		return (free(b), free(str), str = NULL, NULL);
	return (loading_line(t, &p, &b, &str));
}
