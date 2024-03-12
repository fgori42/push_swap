/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:54:55 by fgori             #+#    #+#             */
/*   Updated: 2024/03/12 13:56:05 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	sort_arr(int *arr, int n)
{
	int	i;
	int	temp;

	while (arr[n])
	{
		i = 0;
		while (n > 0)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
			i++;
		}
		n--;
	}
}

int	take_str(t_list *a)
{
	int	*r;
	int	i;

	r = (int *)malloc(ft_lstsize(a) * sizeof(int));
	if (!r)
		return (perror("error\ninallocated r"), -1);
	i = 0;
	while (i < ft_lstsize(a) - 1)
	{
		r[i++] = a->content;
		a = a->next;
	}
	sort_arr(r, ft_lstsize(a));
	i = 0;
	while (i < ft_lstsize(a) / 2)
		i++;
	return (r[i]);
}