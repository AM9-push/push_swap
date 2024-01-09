/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:24:49 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:59:51 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_lstnew(int n)
{
	t_stack		*t;
	static int	indice;

	indice = 0;
	t = malloc(sizeof(t_stack));
	if (!t)
		return (NULL);
	t->der = NULL;
	t->i_dice = indice++;
	t->num = n;
	t->push_cost = 0;
	t->dev = NULL;
	return (t);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*t;

	if (!lst || !new)
		return ;
	t = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (t->dev)
			t = t->dev;
		t->dev = new;
		new->der = t;
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->dev = *lst;
	(*lst)->der = new;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->dev)
		lst = lst->dev;
	return (lst);
}

void	ft_freelist(t_stack **l)
{
	t_stack	*t;
	t_stack	*p;

	t = *l;
	p = NULL;
	while (t)
	{
		p = t->dev;
		free(t);
		t = p;
	}
}
