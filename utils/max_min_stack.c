/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:00 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:28:23 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_maximum(t_stack *stack, t_stack *pt_stack)
{
	t_stack	*pt_max;

	pt_max = NULL;
	while (stack && stack->num < pt_stack->num)
		stack = stack->dev;
	if (stack)
		pt_max = stack;
	while (stack)
	{
		if (stack->num > pt_stack->num && stack->num < pt_max->num)
			pt_max = stack;
		stack = stack->dev;
	}
	return (pt_max);
}

t_stack	*max_minimum(t_stack *stack, t_stack *pt_stack)
{
	t_stack	*pt_min;

	pt_min = NULL;
	while (stack && stack->num > pt_stack->num)
		stack = stack->dev;
	if (stack)
		pt_min = stack;
	while (stack)
	{
		if (stack->num < pt_stack->num && stack->num > pt_min->num)
			pt_min = stack;
		stack = stack->dev;
	}
	return (pt_min);
}

t_stack	*min_minimum(t_stack *stack, t_stack *pt_stack)
{
	t_stack	*pt_min;

	pt_min = NULL;
	while (stack && stack->num > pt_stack->num)
		stack = stack->dev;
	if (stack)
		pt_min = stack;
	while (stack)
	{
		if (stack->num < pt_stack->num && stack->num < pt_min->num)
			pt_min = stack;
		stack = stack->dev;
	}
	return (pt_min);
}

t_stack	*max_maximum(t_stack *stack, t_stack *pt_stack)
{
	t_stack	*pt_max;

	pt_max = NULL;
	while (stack && stack->num < pt_stack->num)
		stack = stack->dev;
	if (stack)
		pt_max = stack;
	while (stack)
	{
		if (stack->num > pt_stack->num && stack->num > pt_max->num)
			pt_max = stack;
		stack = stack->dev;
	}
	return (pt_max);
}
