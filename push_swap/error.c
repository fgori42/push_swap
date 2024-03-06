/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:25:35 by fgori             #+#    #+#             */
/*   Updated: 2024/02/29 15:00:18 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	put_error(t_list **a, t_list **b, char	*str)
{
	perror(str);
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
	exit (1);
}

int	list_ok(char **mat)
{
	int		i;
	int		j;
	char	*m;

	j = 0;
	while (mat[j + 1])
	{
		m = mat[j];
		i = j + 1;
		while (mat[i])
		{
			if (ft_strlen(m) == ft_strlen(mat[i])
				&& ft_strncmp(m, mat[i], ft_strlen(m)) == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
