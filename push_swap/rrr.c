/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:20:12 by fgori             #+#    #+#             */
/*   Updated: 2024/02/23 15:38:38 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rra(t_list **list, char c)
{
	t_list	*temp;
	t_list	*temp2;

	if (!list)
		return ;
	temp = *list;
	while (temp && temp->next->next != NULL)
	{
		temp = temp->next;
		temp2 = temp->next;
	}
	ft_lstadd_front(list, temp2);
	temp->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_list **listA, t_list **listB)
{
	rra(listA, 'c');
	rra(listB, 'c');
	ft_printf("rrr\n");
}

// // Funzione per creare una lista casuale di numeri
//t_list *creaListaCasuale(int lunghezza)
//{
//    t_list *lista = NULL;
//    t_list *nuovo;

//    for (int i = 0; i < lunghezza; i++)
//    {
//	    nuovo = malloc(sizeof(t_list));
//	    nuovo->content = rand() % 100; // Genera un numero casuale tra 0 e 99
//        nuovo->next = lista;
//        lista = nuovo;
//    }

//    return lista;
//}

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
//	rrr(lista1, lista2);

//     // Stampare le liste dopo la chiamata alla funzione
//     printf("Lista 1 dopo push: ");
//     stampaLista(*lista1);
//     printf("Lista 2 dopo push: ");
//     stampaLista(*lista2);

//     return 0;
// }
