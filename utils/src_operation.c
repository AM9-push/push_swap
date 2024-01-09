/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:24:30 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:58:59 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int opr)
{
	t_stack	*pt_1;
	t_stack	*pt_2;
	t_stack	*pt_3;

	pt_1 = *stack;
	pt_2 = pt_1->dev;
	pt_3 = pt_2->dev;
	pt_1->dev = pt_3;
	if (pt_3)
		pt_3->der = pt_1;
	pt_1->der = pt_2;
	pt_2->dev = pt_1;
	pt_2->der = NULL;
	(pt_1->i_dice)++;
	(pt_2->i_dice)--;
	*stack = pt_2;
	if (opr == 2)
		write(1, "sb\n", 3);
	else if (opr == 1)
		write(1, "sa\n", 3);
}

void	push(t_stack **stack_a, t_stack **stack_b, int opr)
{
	t_stack	*pt_stack;

	pt_stack = *stack_a;
	*stack_a = (*stack_a)->dev;
	if (*stack_a)
		(*stack_a)->der = NULL;
	pt_stack->dev = *stack_b;
	if (*stack_b)
		(*stack_b)->der = pt_stack;
	*stack_b = pt_stack;
	sort_i_dice(stack_a);
	sort_i_dice(stack_b);
	if (opr == 2)
		write(1, "pb\n", 3);
	else if (opr == 1)
		write(1, "pa\n", 3);
}

void	rotate(t_stack **stack, int opr)
{
	t_stack	*pt_stack;
	t_stack	*pt_last;

	pt_stack = *stack;
	pt_last = ft_lstlast(*stack);
	*stack = (*stack)->dev;
	pt_stack->dev = NULL;
	(*stack)->der = NULL;
	pt_stack->der = pt_last;
	pt_last->dev = pt_stack;
	sort_i_dice(stack);
	if (opr == 2)
		write(1, "rb\n", 3);
	else if (opr == 1)
		write(1, "ra\n", 3);
}

void	reverse(t_stack **stack, int opr)
{
	t_stack	*pt_stack;
	t_stack	*pt_last;

	pt_last = ft_lstlast(*stack);
	pt_stack = pt_last->der;
	pt_last->der = NULL;
	pt_stack->dev = NULL;
	pt_last->dev = *stack;
	(*stack)->der = pt_last;
	*stack = (*stack)->der;
	sort_i_dice(stack);
	if (opr == 2)
		write(1, "rrb\n", 4);
	else if (opr == 1)
		write(1, "rra\n", 4);
}
