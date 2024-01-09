/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:28:28 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:25:18 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_cost(t_stack *stack, t_stack *pt_stack)
{
	int	size;
	int	cost;
	int	i;

	size = ft_lstsize(stack);
	cost = 0;
	if ((size / 2) >= pt_stack->i_dice)
	{
		i = pt_stack->i_dice;
		while (i-- > 0)
			cost++;
	}
	else
	{
		while (pt_stack->i_dice + 1 < size--)
			cost++;
		cost++;
	}
	return (cost);
}

void	cost_stack_cmplete(t_stack **stack_a, t_stack **stack_b,
		t_stack *pt_stack_a, t_stack *pt_min)
{
	if (pt_stack_a->i_dice && pt_min->i_dice && check_up_down(*stack_a,
			pt_stack_a) == check_up_down(*stack_b, pt_min))
	{
		if (target_cost(*stack_a, pt_stack_a) > target_cost(*stack_b, pt_min))
			pt_stack_a->push_cost = target_cost(*stack_a, pt_stack_a) + 1;
		else
			pt_stack_a->push_cost = target_cost(*stack_b, pt_min) + 1;
	}
	else
		pt_stack_a->push_cost = target_cost(*stack_a, pt_stack_a)
			+ target_cost(*stack_b, pt_min) + 1;
}

void	cost_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pt_stack_a;
	t_stack	*pt_min;

	pt_stack_a = *stack_a;
	while (pt_stack_a)
	{
		pt_min = max_minimum(*stack_b, pt_stack_a);
		if (!pt_min)
			pt_stack_a->push_cost = target_cost(*stack_a, pt_stack_a)
				+ target_cost(*stack_b, max_maximum(*stack_b, pt_stack_a)) + 1;
		else
			cost_stack_cmplete(stack_a, stack_b, pt_stack_a, pt_min);
		pt_stack_a = pt_stack_a->dev;
	}
}

void	push_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pt_stack;
	t_stack	*pt_cost;

	pt_cost = *stack_a;
	pt_stack = pt_cost->dev;
	while (pt_stack)
	{
		if (pt_stack->push_cost == 1)
		{
			for_opt(stack_a, stack_b, pt_stack, pt_cost);
			return ;
		}
		if (pt_stack->push_cost < pt_cost->push_cost)
			pt_cost = pt_stack;
		pt_stack = pt_stack->dev;
	}
	pt_stack = min_maximum(*stack_b, pt_cost);
	if (pt_stack)
		for_opt(stack_a, stack_b, pt_stack, pt_cost);
	else
		for_opt(stack_a, stack_b, min_minimum(*stack_b, pt_cost), pt_cost);
}
