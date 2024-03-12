/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:30:44 by fgori             #+#    #+#             */
/*   Updated: 2024/03/12 14:08:14 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	move(t_list **start, t_list **fin, char c, int index)
{
	t_list	*temp;
	t_list	*temp2;
	char	j;

	if (c == 'a')
		j = 'b';
	else if (c == 'b')
		j = 'a';
	temp = *start;
	temp2 = *fin;
	while (temp->index != index)
		temp = temp->next;
	while (temp2->index != temp->goal)
		temp2 = temp2->next;
	if (temp->middle == temp2->middle)
	{
		while (temp->price > 0 && temp2->price > 0)
		{
			if (temp->middle == 1)
				rr(fin, start);
			else if (temp->middle == 2)
				rrr(fin, start);
			temp->price--;
			temp2->price--;
			doble_set(start, fin);
		}
		while (temp->price > 0)
		{
			if (temp->middle == 1)
				ra(start, c);
			else if (temp->middle == 2)
				rra(start, c);
			temp->price--;
			doble_set(start, fin);
		}
		while (temp2->price > 0)
		{
			if (temp2->middle == 1)
				ra(fin, j);
			else if (temp2->middle == 2)
				rra(fin, j);
			temp2->price--;
			doble_set(start, fin);
		}
	}
	if (temp->middle != temp2->middle)
	{
		while (temp->price > 0)
		{
			if (temp->middle == 1)
				ra(start, c);
			else if (temp->middle == 2)
				rra(start, c);
			temp->price--;
			doble_set(start, fin);
		}
		while (temp2->price > 0)
		{
			if (temp2->middle == 1)
				ra(fin, j);
			else if (temp2->middle == 2)
				rra(fin, j);
			temp2->price--;
			doble_set(start, fin);
		}
	}
	push(fin, start, c);
	doble_set(start, fin);
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

void	set_zero(t_list **a)
{
	int	pos;

	set_index(a);
	pos = find_min(*a);
	while (!(is_in_order(*a)))
	{
		if (pos <= ft_lstsize(*a) / 2)
			ra(a, 'a');
		else if (pos > ft_lstsize(*a) / 2)
			rra(a, 'a');
	}
}

void	plus(t_list **a, t_list **b)
{
	int	n;
	int	ck;

	n = ft_lstsize(*a);
	ck = take_str(*a);
	while (n-- > 3)
	{
		if ((*a)->content < ck)
		{
			push(b, a, 'a');
			ra(b, 'b');
		}
		else
			push(b, a, 'a');
	}
	sort_three(a);
	doble_set(a, b);
	while (ft_lstsize(*b) >= 1)
	{
		cheak_goal_max(*b, *a);
		doble_set(a, b);
		make_cheapest(b, a, 'b');
	}
	if (!(is_in_order(*a)))
		set_zero(a);
}
