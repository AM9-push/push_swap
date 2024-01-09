/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:11:26 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:35:09 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	longatoi(const char *str, int i, int j, int *v_rf)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n2 = n1;
		n1 = (n2 * 10) + (str[i] - 48);
		if (n2 > n1)
		{
			if (n1 == -2147483648 && j)
				return (-2147483648);
			*v_rf = 0;
			return (-1);
		}
		i++;
	}
	if (j)
		return (-n1);
	return (n1);
}

int	ft_atoi(const char *str, int *v_rf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			j++;
	return (longatoi(str, i, j, v_rf));
}
