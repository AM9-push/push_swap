/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:26:09 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:50:20 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	occ_check(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
			return (0);
		stack = stack->dev;
	}
	return (1);
}

int	sort_check(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->dev)
	{
		if (stack->num > (stack->dev)->num)
			return (0);
		stack = stack->dev;
	}
	return (1);
}

int	whsp_check(char const *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i] && s[i] == 32)
		i++;
	if (!s[i])
		return (0);
	while (*s)
	{
		if (*s < 32)
			return (0);
		s++;
	}
	return (1);
}
