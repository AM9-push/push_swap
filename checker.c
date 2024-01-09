/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:01:16 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 12:37:14 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus/checker.h"

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

void	error_so_exit(t_stack **stack_a, char **p, int i)
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
	char	*opr;

	stack_a = NULL;
	stack_b = NULL;
	opr = NULL;
	if (ac > 1)
	{
		parting_input(ac, av, &stack_a);
		opr = get_next_line(0);
		while (opr)
		{
			sort_stack_a(opr, &stack_a, &stack_b);
			free(opr);
			opr = get_next_line(0);
		}
		if (sort_check(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_freelist(&stack_a);
		ft_freelist(&stack_b);
	}
}
