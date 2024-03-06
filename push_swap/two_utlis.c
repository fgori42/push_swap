/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:15:49 by fgori             #+#    #+#             */
/*   Updated: 2024/02/29 16:02:29 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_atoi_sw(const char *nptr, t_list **ast, t_list **bst)
{
	int		a;
	long	b;
	int		c;

	a = 0;
	b = 0;
	c = 1;
	if (nptr[a] == '+' || nptr[a] == '-')
	{
		if (nptr[a] == '-')
			c *= -1;
		a++;
	}
	while ((nptr[a] != '\0') && (nptr[a] <= '9') && (nptr[a] >= '0'))
	{
		b = (b * 10) + ((nptr[a] + 2) % 10);
		if ((c == -1 && b >= 2147483648)
			|| (c == 1 && b > 21474883647))
			put_error(ast, bst, "ERROR\nwrong nuber");
		a++;
	}
	if (a < (int)ft_strlen(nptr))
		return (0);
	b *= c;
	return (b);
}

int	pre_atoi(char *str, t_list **a, t_list **b)
{
	int	j;

	str = ft_strtrim(str, " 	");
	j = ft_atoi_sw(str, a, b);
	if (j == 0 && ft_strlen(str) > 1)
		put_error(a, b, "ERROR\nalpha in nbr");
	return (j);
}
