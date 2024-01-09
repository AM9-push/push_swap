/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:05 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/08 22:28:19 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_up_down(t_stack *stack, t_stack *pt_stack)
{
	if ((ft_lstsize(stack) / 2) >= pt_stack->i_dice)
		return (1);
	else
		return (0);
}

void	should_org(t_stack **stack, t_stack *pt_stack, int op_stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (pt_stack)
	{
		if ((size / 2) >= pt_stack->i_dice)
			while (pt_stack->i_dice)
				rotate(stack, op_stack);
		else
			while (pt_stack->i_dice)
				reverse(stack, op_stack);
	}
}

void	should_rr_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *pt_stack_a,
		t_stack *pt_stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (pt_stack_b)
	{
		if ((size / 2) >= pt_stack_a->i_dice)
		{
			while (pt_stack_a->i_dice && pt_stack_b->i_dice)
				rr(stack_a, stack_b);
		}
		else
		{
			while (pt_stack_a->i_dice && pt_stack_b->i_dice)
				rrr(stack_a, stack_b);
		}
	}
}

void	for_opt(t_stack **stack_a, t_stack **stack_b, t_stack *pt_stack,
		t_stack *pt_cost)
{
	if (pt_stack->i_dice && pt_cost->i_dice && check_up_down(*stack_b,
			pt_stack) == check_up_down(*stack_a, pt_cost))
	{
		should_rr_rrr(stack_a, stack_b, pt_cost, pt_stack);
		if (pt_cost->i_dice)
			should_org(stack_a, pt_cost, 2);
		else if (pt_stack->i_dice)
			should_org(stack_b, pt_stack, 1);
		push(stack_a, stack_b, 1);
	}
	else
	{
		should_org(stack_a, pt_cost, 2);
		should_org(stack_b, pt_stack, 1);
		push(stack_a, stack_b, 1);
	}
}
