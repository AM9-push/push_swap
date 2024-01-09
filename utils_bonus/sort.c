/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:05 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:36:16 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	should_go(t_stack **stack_a, t_stack **stack_b, char *opr)
{
	write(2, "Error\n", 7);
	free(opr);
	ft_freelist(stack_a);
	ft_freelist(stack_b);
	exit(1);
}

void	sort_stack_b(char *opr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(opr, "sb\n"))
		swap(stack_b, 3);
	else if (!ft_strcmp(opr, "pa\n"))
		push(stack_b, stack_a, 3);
	else if (!ft_strcmp(opr, "rb\n"))
		rotate(stack_b, 3);
	else if (!ft_strcmp(opr, "rrb\n"))
		reverse(stack_b, 3);
	else if (!ft_strcmp(opr, "ss\n"))
	{
		swap(stack_a, 3);
		swap(stack_b, 3);
	}
	else if (!ft_strcmp(opr, "rr\n"))
	{
		rotate(stack_a, 3);
		rotate(stack_b, 3);
	}
	else if (!ft_strcmp(opr, "rrr\n"))
	{
		reverse(stack_a, 3);
		reverse(stack_b, 3);
	}
	else
		should_go(stack_a, stack_b, opr);
}

void	sort_stack_a(char *opr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(opr, "sa\n"))
		swap(stack_a, 3);
	else if (!ft_strcmp(opr, "ra\n"))
		rotate(stack_a, 3);
	else if (!ft_strcmp(opr, "rra\n"))
		reverse(stack_a, 3);
	else if (!ft_strcmp(opr, "pb\n"))
		push(stack_a, stack_b, 3);
	else
		sort_stack_b(opr, stack_a, stack_b);
}
