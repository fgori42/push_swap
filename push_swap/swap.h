/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:51:01 by fgori             #+#    #+#             */
/*   Updated: 2024/03/12 13:56:26 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

void	swap(t_list **lst, int i);
void	sswap(t_list **lstA, t_list **listB);
void	push(t_list **listA, t_list **listB, char c);
void	ra(t_list **list, char c);
void	rr(t_list **listA, t_list **listB);
void	rra(t_list **list, char c);
void	rrr(t_list **listA, t_list **listB);
t_list	*ft_lstnewint(int content);
void	controll(t_list **a, t_list **b, int i);
int		list_ok(char **mat);
int		is_in_order(t_list *a);
void	put_error(t_list **a, t_list **b, char	*str);
int		ft_atoi_sw(const char *nptr, t_list **ast, t_list **bst);
int		pre_atoi(char *str, t_list **a, t_list **b);
void	sort_multi(t_list **a, t_list **b, int nbr);
void	set_index(t_list **a);
void	sort_three(t_list **a);
void	make_cheapest(t_list **start, t_list **finish, char c);
void	doble_set(t_list **a, t_list **b);
void	plus(t_list **a, t_list **b);
void	cheak_goal_min(t_list *start, t_list *goal);
void	cheak_goal_max(t_list *stak_start, t_list *stack_goal);
int		find_max(t_list *a);
int		find_min(t_list *a);
void	set_zero(t_list **a);
int		take_str(t_list *a);
#endif