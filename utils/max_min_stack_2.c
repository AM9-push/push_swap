/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_stack_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:07:51 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:28:07 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*maximum(t_stack *stack)
{
	t_stack	*pt_max;

	pt_max = stack;
	stack = stack->dev;
	while (stack)
	{
		if (stack->num > pt_max->num)
			pt_max = stack;
		stack = stack->dev;
	}
	return (pt_max);
}

t_stack	*minimum(t_stack *stack)
{
	t_stack	*pt_min;

	pt_min = stack;
	stack = stack->dev;
	while (stack)
	{
		if (stack->num < pt_min->num)
			pt_min = stack;
		stack = stack->dev;
	}
	return (pt_min);
}
