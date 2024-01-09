/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:36:23 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:36:17 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	countw(char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] == 32 && i && s[i - 1] != 32)
			j++;
		i++;
	}
	if (s[i - 1] != 32)
		j++;
	return (j);
}

void	copysplit(char *d, char const *s, int i, int j)
{
	int	k;

	k = 0;
	while (i < j)
		d[k++] = s[i++];
	d[k] = '\0';
}

int	kouraydiss(char const *s, int *j, int *l)
{
	int	k;

	k = 0;
	while (s[*j] == 32)
		(*j)++;
	*l = *j;
	while (s[*j] && s[(*j)++] != 32)
		k++;
	if (!s[*j] && s[(*j) - 1] != 32)
		(*j)++;
	return (k);
}

char	**free_echoue(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(p[i++]);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	**p;
	char	*t;
	int		i;
	int		j;
	int		l;

	if (!s || !whsp_check(s))
		return (NULL);
	p = malloc((countw(s) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	l = 0;
	while (i < countw(s))
	{
		t = malloc(kouraydiss(s, &j, &l) + 1);
		if (!t)
			return (free_echoue(p, i));
		copysplit(t, s, l, j - 1);
		p[i++] = t;
	}
	p[i] = 0;
	return (p);
}
