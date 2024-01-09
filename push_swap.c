/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:28:23 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:42:42 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

int	is_nmbr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
			return (0);
		str++;
	}
	if (*(str - 1) == '-' || *(str - 1) == '+')
		return (0);
	return (1);
}

void	let_is_go(t_stack **stack_a, t_stack **stack_b)
{
	int	moy;

	moy = (maximum(*stack_a)->num + minimum(*stack_a)->num) / 2;
	push(stack_a, stack_b, 2);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->num < moy)
		{
			push(stack_a, stack_b, 2);
			rotate(stack_b, 2);
		}
		else
			push(stack_a, stack_b, 2);
	}
	magic_sort(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		cost_stack(stack_b, stack_a);
		push_cost(stack_b, stack_a);
	}
	last_touch(stack_a);
}

void	error_so_exit(t_stack **stack_a, char **p__tr, int i_dice)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	parting_input(int ac, char *av[], t_stack **stack_a)
{
	int		ac_dice;
	int		i_dice;
	int		nbr;
	int		v_rf;
	char	**p__tr;

	ac_dice = 1;
	v_rf = 1;
	p__tr = NULL;
	while (ac_dice < ac)
	{
		i_dice = 0;
		p__tr = ft_split(av[ac_dice++]);
		if (!p__tr)
			error_so_exit(stack_a, p__tr, i_dice);
		while (p__tr[i_dice])
		{
			nbr = ft_atoi(p__tr[i_dice], &v_rf);
			if (!is_nmbr(p__tr[i_dice++]) || !occ_check(*stack_a, nbr)
				|| (nbr == -1 && !v_rf))
				error_so_exit(stack_a, p__tr, i_dice);
			ft_lstadd_back(stack_a, ft_lstnew(nbr));
		}
		free_echoue(p__tr, i_dice);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		parting_input(ac, av, &stack_a);
		if (!sort_check(stack_a))
		{
			if (ft_lstsize(stack_a) == 2)
				swap(&stack_a, 1);
			else if (ft_lstsize(stack_a) == 3)
				magic_sort(&stack_a);
			else
				let_is_go(&stack_a, &stack_b);
		}
		ft_freelist(&stack_a);
	}
}
