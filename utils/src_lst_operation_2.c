/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_lst_operation_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:55:48 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/08 22:24:28 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_i_dice(t_stack **stack)
{
	t_stack	*pt_stack;
	int		i;

	pt_stack = *stack;
	i = 0;
	while (pt_stack)
	{
		pt_stack->i_dice = i++;
		pt_stack = pt_stack->dev;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 3);
	swap(stack_b, 3);
	write(1, "ss\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 3);
	rotate(stack_b, 3);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a, 3);
	reverse(stack_b, 3);
	write(1, "rrr\n", 4);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->dev)
	{
		i++;
		lst = lst->dev;
	}
	return (i + 1);
}
