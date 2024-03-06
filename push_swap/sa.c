/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:27:43 by fgori             #+#    #+#             */
/*   Updated: 2024/02/23 13:54:27 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include <stdio.h> 

void	swap(t_list **lst, int i)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return ;
	else
	{
		temp = (*lst);
		*lst = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)-> next = temp;
	}
	if (i == 1)
		ft_putendl_fd("sa", 1);
	else if (i == 2)
		ft_putendl_fd("sb", 1);
}

void	sswap(t_list **lstA, t_list **listB)
{
	swap(lstA, 3);
	swap(listB, 3);
	ft_printf("ss\n");
}
// int	main(void)
// {
//  	t_list *list = NULL;
//     int element1 = 1;
//     int element2 = 2;
//     int element3 = 3;
// 	int i =0;

//     ft_lstadd_front(&list, ft_lstnew(&element3));
//     ft_lstadd_front(&list, ft_lstnew(&element2));
//     ft_lstadd_front(&list, ft_lstnew(&element1));
// 	swap(&list, 1);
//     t_list *current = list;
//     while (i < 3) {
//         printf("%d ", *(int *)(current->content));
//         current = current->next;
// 		i++;
//     }
// 	return 0;
// }