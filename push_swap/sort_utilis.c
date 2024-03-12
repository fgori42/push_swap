/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:44:43 by fgori             #+#    #+#             */
/*   Updated: 2024/03/08 13:26:34 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	find_max(t_list *a)
{
	long	n;
	t_list	*tmp;
	t_list	*id;

	if (!a)
		perror("Error\nnot found list");
	tmp = a;
	id = a;
	n = LONG_MIN;
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

int	find_min(t_list *a)
{
	long	n;
	t_list	*tmp;
	t_list	*id;

	if (!a)
		perror("error\nnot found list");
	tmp = a;
	id = a;
	n = LONG_MAX;
	while (tmp)
	{
		if (n > tmp->content)
			n = tmp->content;
		tmp = tmp->next;
	}
	while (id->content != n)
		id = id->next;
	return (id->index);
}

void	only_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) >= 1)
	{
		cheak_goal_max((*b), (*a));
		make_cheapest(b, a, 'b');
	}
	set_zero(a);
}

void	sort_multi(t_list **a, t_list **b, int nbr)
{
	int		max;

	max = 2;
	while (nbr > 3 && max > 0)
	{
		push(b, a, 'a');
		nbr--;
		max--;
	}
	if (ft_lstsize(*a) + ft_lstsize(*b) <= 5)
	{
		sort_three(a);
		doble_set(a, b);
		only_five(a, b);
	}
	else
	{
		doble_set(a, b);
		plus(a, b);
	}
}
