/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_touch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:26:09 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/08 22:23:41 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic_sort(t_stack **stack)
{
	t_stack	*pt_1;
	t_stack	*pt_2;
	t_stack	*pt_3;

	pt_1 = *stack;
	pt_2 = pt_1->dev;
	pt_3 = pt_2->dev;
	if (pt_1->num > pt_2->num && pt_2->num < pt_3->num && pt_3->num < pt_1->num)
	{
		rotate(stack, 1);
	}
	else if (pt_1->num < pt_2->num && pt_2->num > pt_3->num
		&& pt_3->num < pt_1->num)
	{
		reverse(stack, 1);
	}
	else
	{
		swap(stack, 1);
		if (pt_1->num > pt_3->num || pt_1->num < pt_2->num)
			magic_sort(stack);
	}
}

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
	while (stack->dev)
	{
		if (stack->num > (stack->dev)->num)
			return (0);
		stack = stack->dev;
	}
	return (1);
}

void	last_touch(t_stack **stack)
{
	t_stack	*pt_1;
	t_stack	*pt_2;

	pt_1 = *stack;
	pt_2 = pt_1->dev;
	while (pt_2)
	{
		if (pt_1->num > pt_2->num)
		{
			should_org(stack, pt_2, 1);
			break ;
		}
		pt_1 = pt_2;
		pt_2 = pt_2->dev;
	}
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
