/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:30:44 by fgori             #+#    #+#             */
/*   Updated: 2024/03/06 12:29:31 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	move(t_list **start, t_list **fin, char c, int index)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *start;
	temp2 = *fin;
	while (temp->index != index)
		temp = temp->next;
	while (temp2->index != temp->goal)
		temp2 = temp2->next;
	if (temp->middle != temp2->middle)
	{
		while (temp->price > 0)
		{
			if (temp->middle == 1)
				ra(start, c);
			else if (temp->middle == 2)
				rra(start, c);
			temp->price--;
		}
		while (temp2->price > 0)
		{
			if (temp2->middle == 1)
				ra(fin, 'a');
			else if (temp2->middle == 2)
				rra(fin, 'a');
			temp2->price--;
		}
	}
	if (temp->middle == temp2->middle)
	{
		while (temp->price > temp2->price && temp->price > 0 && temp2->price > 0)
		{
			if (temp->middle == 1)
				rr(fin, start);
			else if (temp->middle == 2)
				rrr(fin, start);
			temp->price--;
			temp2->price--;
		}
		while (temp->price > 0)
		{
			if (temp->middle == 1)
				ra(start, c);
			else if (temp->middle == 2)
				rra(start, c);
			temp->price--;
		}
		while (temp2->price > 0)
		{
			if (temp2->middle == 1)
				ra(fin, 'a');
			else if (temp2->middle == 2)
				rra(fin, 'a');
			temp2->price--;
		}
	}
	push(fin, start, c);
}

void	make_cheapest(t_list **start, t_list **finish, char c)
{
	t_list	*temp;
	t_list	*obj;
	t_list	*chip;
	int		i;
	int		j;

	temp = *start;
	j = INT_MAX;
	while (temp)
	{
		obj = *finish;
		while (obj)
		{
			while (obj->index != temp->goal)
				obj = obj->next;
			if (temp->middle != obj->middle)
				i = temp->price + obj->price;
			else if (temp->middle == obj->middle)
			{
				if (temp->price >= obj->price)
					i = temp->price;
				else
					i = obj->price;
			}
			break ;
		}
		if (i < j)
		{
			j = i;
			chip = temp;
		}
		temp = temp->next;
	}
	move(start, finish, c, chip->index);
}
