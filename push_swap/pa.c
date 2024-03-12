/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:31:01 by fgori             #+#    #+#             */
/*   Updated: 2024/03/07 14:58:07 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

//t_list	*ft_lstnewint(int content)
//{
//	t_list	*new;

//	new = (void *)malloc(sizeof(t_list));
//	if (!content)
//	{
//		new->content = 0;
//		new->next = 0;
//	}
//	if (!new)
//		return (NULL);
//	new->content = content;
//	new->next = NULL;
//	return (new);
//}

void	pu(t_list **listA, t_list **listB)
{
	t_list	*temp;
	t_list	*to_nul;

	if (!listA)
		return ;
	to_nul = *listB;
	temp = *listB;
	if (!listA)
	{
		temp->next = NULL;
		*listA = temp;
	}
	else
	{
		ft_lstadd_front(listA, ft_lstnewint((*listB)->content));
	}
	(*listB) = (*listB)->next;
	ft_lstdelone(to_nul);
}

void	push(t_list **listA, t_list **listB, char c)
{
	pu(listA, listB);
	if (c == 'a')
		ft_printf("pb\n");
	if (c == 'b')
		ft_printf("pa\n");
}

// // Funzione per creare una lista casuale di numeri
// t_list *creaListaCasuale(int lunghezza)
// {
//     t_list *lista = NULL;
//     t_list *nuovo;

//     for (int i = 0; i < lunghezza; i++)
//     {
//         nuovo = malloc(sizeof(t_list));
//         nuovo->content = rand() % 100; // Genera un numero casuale tra 0 e 99
//         nuovo->next = lista;
//         lista = nuovo;
//     }

//     return lista;
// }

// // Funzione per stampare una lista
// void stampaLista(t_list *lista)
// {
//     while (lista != NULL)
//     {
//         printf("%d ", lista->content);
//         lista = lista->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     // Creare due liste casuali di numeri
//     t_list **lista1 = malloc(sizeof(t_list *));
//     *lista1 = creaListaCasuale(5);

//     t_list **lista2 = malloc(sizeof(t_list *));
//     *lista2 = creaListaCasuale(5);

//     // Stampare le liste originali
//     printf("Lista 1: ");
//     stampaLista(*lista1);
//     printf("Lista 2: ");
//     stampaLista(*lista2);

//     // Testare la funzione push
//     push(lista1, lista2, 1);

//     // Stampare le liste dopo la chiamata alla funzione
//     printf("Lista 1 dopo push: ");
//     stampaLista(*lista1);
//     printf("Lista 2 dopo push: ");
//     stampaLista(*lista2);

//     return 0;
// }
