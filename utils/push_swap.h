
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:27:16 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 14:25:40 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct noode
{
	struct noode	*der;
	int				i_dice;
	long			num;
	int				push_cost;
	struct noode	*dev;
}					t_stack;

int					ft_atoi(const char *str, int *verf);
t_stack				*ft_lstnew(int n);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				ft_freelist(t_stack **l);
int					ft_lstsize(t_stack *lst);
void				sort_i_dice(t_stack **stack);
void				swap(t_stack **stack, int opr);
void				push(t_stack **stack_a, t_stack **stack_b, int opr);
void				rotate(t_stack **stack, int opr);
void				reverse(t_stack **stack, int opr);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
t_stack				*min_maximum(t_stack *stack, t_stack *pt_stack);
t_stack				*max_minimum(t_stack *stack, t_stack *pt_stack);
t_stack				*min_minimum(t_stack *stack, t_stack *pt_stack);
t_stack				*max_maximum(t_stack *stack, t_stack *pt_stack);
int					check_up_down(t_stack *stack, t_stack *pt_stack);
void				should_org(t_stack **stack, t_stack *pt_stack,
						int op_stack);
void				should_rr_rrr(t_stack **stack_a, t_stack **stack_b,
						t_stack *pt_stack_a, t_stack *pt_stack_b);
void				for_opt(t_stack **stack_a, t_stack **stack_b,
						t_stack *pt_stack, t_stack *pt_cost);
void				magic_sort(t_stack **stack);
int					occ_check(t_stack *stack, int num);
int					sort_check(t_stack *stack);
void				last_touch(t_stack **stack);
int					whsp_check(char const *s);
int					target_cost(t_stack *stack, t_stack *pt_stack);
void				cost_stack(t_stack **stack_a, t_stack **stack_b);
void				push_cost(t_stack **stack_a, t_stack **stack_b);
char				**ft_split(char const *s);
char				**free_echoue(char **p, int j);
t_stack				*maximum(t_stack *stack);
t_stack				*minimum(t_stack *stack);

#endif
