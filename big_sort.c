/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
	Fonction permettant d'envoyer les elements de la stack b sur la stack a. 
	On va boucler tant que l'on a des elements sur b et on envoie la fonction
	pa qui push sur la stack a. 
*/
void	while_pa(t_stack **a, t_stack **b, int elem_on_b)
{
	int	i;

	i = 0;
	while (i < elem_on_b)
	{
		pa(a, b);
		i++;
	}
}

/*
	Algorithme radix qui va permettre de comparer chaque nombre en binaire
	et les trier.
	On boucle tant que i n'est pas a 32 puis on reboucle tant que j n'est
	pas plus grand que le nb d'element dans la liste. On va ensuite comparer
	chaque fois le dernier element de la liste en decalant de ix nb de bit&1
	si c'est plus grand on ra de sorte a avoir toujours le plus grand nombre
	en comparaison. Sinon on envoie les elements sur la stack b et on incremente 
	la variable qui compte le nb d'element present sur la stack b.
	Une fois terminer on envoi la fonction while pa. 
*/
void	big_sort(t_stack *a, t_stack *b, int nb_element)
{
	int	i;
	int	j;
	int	elem;
	int	elem_on_b;

	i = -1;
	while (++i < 32)
	{
		if (in_order(a))
			return ;
		elem_on_b = 0;
		j = -1;
		while (++j < nb_element)
		{
			elem = *(int *) ft_lstlast(a)->content;
			if ((elem >> i) & 1)
				ra(a);
			else
			{
				pb(&a, &b);
				elem_on_b++;
			}
		}
		while_pa(&a, &b, elem_on_b);
	}
}
