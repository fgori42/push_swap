/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:32:11 by fgori             #+#    #+#             */
/*   Updated: 2024/03/05 12:22:47 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	matcont(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		i++;
	}
	return (i);
}

//void	stampaLista(t_list *lista)
//{
//	while (lista != NULL)
//	{
//		printf("%d ", lista->content);
//		lista = lista->next;
//	}
//	printf("\n");
//}

void	monostak(t_list **stak, t_list **b, char *str)
{
	char	**temp;
	int		i;
	int		n;

	temp = ft_split(str, ' ');
	if (!temp)
		put_error(stak, b, "error\nmissed slit");
	if (!(list_ok(temp)))
	{
		freeall(temp);
		put_error(stak, b, "ERROr\ndouble number");
	}
	i = matcont(temp) - 1;
	while (i >= 0)
	{
		n = pre_atoi(temp[i], stak, b);
		ft_lstadd_front(stak, ft_lstnewint(n));
		i--;
	}
	freeall(temp);
}

void	pluristak(t_list **stak, t_list **b, char *av[], int ac)
{
	int	n;
	int	i;

	i = 1;
	if (!(list_ok(av)))
		put_error(stak, b, "ERROR\ndouble number");
	while (i < ac)
	{
		n = pre_atoi(av[i], stak, b);
		ft_lstadd_back(stak, ft_lstnewint(n));
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_list	**stak;
	t_list	**stakb;

	if (ac < 2)
		return (perror("ERROR\nto few argument"), 1);
	stak = NULL;
	stakb = NULL;
	stak = malloc(sizeof(t_list *));
	stakb = malloc(sizeof(t_list *));
	if (ac == 2)
		monostak(stak, stakb, av[1]);
	if (ac > 2)
		pluristak(stak, stakb, av, ac);
	controll(stak, stakb, ft_lstsize(*stak));
	//stampaLista(*stak);
	//stampaLista(*stakb);
}

//int main(int ac, char *av[])
//{
//	int i;
//	char *str = "  		ciao";
//	t_list **a;
//	t_list **b;

//	a = NULL;
//	b = NULL;
//	if (ac == 8345)
//		exit (0);
//	str = ft_strtrim(str, "	 ");
////	i = ft_atoi_sw(av[1], a, b);
//	printf("%s", str);
//}