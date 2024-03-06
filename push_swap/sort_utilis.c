/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:44:43 by fgori             #+#    #+#             */
/*   Updated: 2024/03/06 12:32:57 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	stampaLista(t_list *lista)
{
	while (lista != NULL)
	{
		printf("%d ", lista->content);
		lista = lista->next;
	}
	printf("\n");
}

int	find_min(t_list *a)
{
	long	n;
	t_list	*tmp;
	t_list	*id;

	tmp = a;
	id = a;
	n = LONG_MAX;
	while (tmp)
	{
		if (n < tmp->content)
			n = tmp->content;
		tmp = tmp->next;
	}
	while (id->content != n)
		id = id->next;
	return (id->index);
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

void	only_five(t_list **a, t_list **b)
{
	sort_three(a);
	set_index(a);
	set_index(b);
	cheak_goal_max((*b), (*a));
	make_cheapest(b, a, 'b');
	stampaLista(*a);
	stampaLista(*b);
}

void	sort_multi(t_list **a, t_list **b, int nbr)
{
	int	max;

	max = 2;
	while (nbr > 3 || max > 0)
	{
		push(b, a, 'a');
		nbr--;
		max--;
	}
	if (ft_lstsize(*a) + ft_lstsize(*b) == 5)
	{
		only_five(a, b);
	}
	//else
	//	plus(a, b);
}
