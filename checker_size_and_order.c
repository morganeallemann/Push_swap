/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_size_and_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Fonction permettant de verifier si les nombres entres sont deja dans le 
	bon ordre. On boucle tant qu'il y a des elements dans la liste et on 
	compare toujours l'element sur lequel on est avec le suivant. Tant qu'il 
	est plus grand on continue sinon on renvoi 0 pour indiquer que l'ordre 
	n'est pas le bon.
*/
int	in_order(t_stack *a)
{
	while (a->next != NULL)
	{
		if (*(int *)a->content < *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

/*
	Fonction permettant de definir le nombre d'elements entree en parametre.
	La fonction lstsize nous donnera le nombre d'element de la liste chainee.
	On renvera une fonction en fonction du nombre de chiffre a trier.
*/
void	size_checker(t_stack *a, t_stack *b)
{
	int	len;

	len = ft_lstsize(a);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (!(in_order(a)))
			sa(a);
	}
	else if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
	else
		big_sort(a, b, len);
}
