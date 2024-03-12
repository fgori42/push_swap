/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:37:14 by fgori             #+#    #+#             */
/*   Updated: 2024/03/08 12:45:26 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	cheak_goal_min(t_list *start, t_list *goal)
{
	long	chek;
	int		i;
	t_list	*temp;
	t_list	*circol;

	temp = start;
	while (temp)
	{
		i = 0;
		chek = LONG_MIN;
		circol = goal;
		while (circol)
		{
			if (circol->content < temp->content && circol->content > chek)
				i = circol->index;
			if (circol->content < temp->content && circol->content > chek)
				chek = circol->content;
			(circol) = (circol)->next;
		}
		if (chek == LONG_MIN)
			temp->goal = find_max(goal);
		else
			temp->goal = i;
		(temp) = (temp)->next;
	}
}

void	cheak_goal_max(t_list *stak_start, t_list *stack_goal)
{
	long		chek;
	int			i;
	t_list		*tmp;
	t_list		*circol;

	tmp = (stak_start);
	while (tmp)
	{
		i = 0;
		chek = LONG_MAX;
		circol = stack_goal;
		while (circol)
		{
			if (circol->content > tmp->content && circol->content < chek)
				i = circol->index;
			if (circol->content > tmp->content && circol->content < chek)
				chek = circol->content;
			(circol) = (circol)->next;
		}
		if (chek == LONG_MAX)
			tmp->goal = find_min(stack_goal);
		else
			tmp->goal = i;
		(tmp) = (tmp)->next;
	}
}