/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:28:52 by fgori             #+#    #+#             */
/*   Updated: 2024/03/12 14:01:10 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_list	*ft_lstnewint(int content)
{
	t_list	*new;

	new = (void *)malloc(sizeof(t_list));
	if (!content)
	{
		new->content = 0;
		new->next = 0;
	}
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	is_in_order(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	while (!(is_in_order(*a)))
	{
		if ((*a)->content > (*a)->next->content
			&& (*a)->next->content < (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content)
			ra(a, 'a');
		else if ((*a)->content > (*a)->next->content)
			swap(a, 1);
		else if ((*a)->content < (*a)->next->content)
			rra(a, 'a');
		if ((*a)->content > (*a)->next->content)
			swap(a, 1);
	}
}

void	controll(t_list **a, t_list **b, int i)
{
	t_list	*temp;

	temp = *a;
	while (!(is_in_order(temp)))
	{
		if (i == 2)
			ra(a, 'a');
		if (i == 3)
			sort_three(a);
		else
		{
			sort_multi(a, b, i);
		}
	}
}
