/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:16:36 by aachalla          #+#    #+#             */
/*   Updated: 2024/01/09 11:59:35 by aachalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
char				*get_next_line(int fd);
int					ft_isthere(char *s);
int					ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, int size);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin(char **s1, char const *s2, int i);
char				**ft_split(char const *s);
char				**free_echoue(char **p, int j);
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
int					occ_check(t_stack *stack, int num);
int					sort_check(t_stack *stack);
int					whsp_check(char const *s);
char				**ft_split(char const *s);
char				**free_echoue(char **p, int j);
void				sort_stack_a(char *opr, t_stack **stack_a,
						t_stack **stack_b);
void				sort_stack_b(char *opr, t_stack **stack_a,
						t_stack **stack_b);

#endif
