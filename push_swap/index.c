/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:57:20 by fgori             #+#    #+#             */
/*   Updated: 2024/03/12 14:00:53 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	doble_set(t_list **a, t_list **b)
{
	set_index(a);
	set_index(b);
}

void	set_index(t_list **a)
{
	int		i;
	int		mid;
	t_list	*temp;

	i = 0;
	temp = *a;
	mid = ft_lstsize(*a) / 2;
	while (temp)
	{
		(temp)->index = i;
		if (i <= mid)
		{
			(temp)->middle = 1;
			(temp)->price = i;
		}
		else if (i > mid)
		{
			(temp)->middle = 2;
			(temp)->price = ft_lstsize(*a) - i;
		}
		(temp) = (temp)->next;
		i++;
	}
}
