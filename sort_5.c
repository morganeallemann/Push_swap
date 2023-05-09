/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Fonction permettant de mettre le chiffre 0 en 4e position en
	fonction de la position ou il se trouve initialement puis l'envoyer sur
	la stack b. 
*/
void	put_pos_0(t_stack *a, t_stack **b, int index)
{
	if (index == 0)
	{
		rra(a);
		pb(&a, b);
	}
	if (index == 1)
	{
		rra(a);
		rra(a);
		pb(&a, b);
	}
	if (index == 2)
	{
		ra(a);
		ra(a);
		pb(&a, b);
	}
	if (index == 3)
	{
		ra(a);
		pb(&a, b);
	}
	if (index == 4)
		pb(&a, b);
}

/*
	Fonction permettant de mettre le chiffre 1 en 3e position en
	fonction de la position ou il se trouve initialement puis l'envoyer sur
	la stack b. 
*/
void	put_pos_1(t_stack *a, t_stack **b, int index)
{
	if (index == 0)
	{
		rra(a);
		pb(&a, b);
	}
	if (index == 1)
	{
		rra(a);
		rra(a);
		pb(&a, b);
	}
	if (index == 2)
	{
		sa(a);
		pb(&a, b);
	}
	if (index == 3)
	{
		pb(&a, b);
	}
}

/*
	Fonction qui permettera de remettre dans l'ordre une liste de 5
	elements. On declare 2 variables int qui trouveront la position du
	chiffre 0 et 1 dans la liste. On va ensuite envoyer la fonction put_pos_0 
	et 1 et trier les 3 chiffre de la stack a et remettre ensuite le 1
	puis le 0 au debut de la stack a. 
*/
void	sort_5(t_stack *a, t_stack *b)
{
	int	nb_0;
	int	nb_1;

	if (!(in_order(a)))
	{
		nb_0 = find_nb(a, 0);
		put_pos_0(a, &b, nb_0);
		nb_1 = find_nb(a, 1);
		put_pos_1(a, &b, nb_1);
		sort_3(a);
		pa(&a, &b);
		pa(&a, &b);
	}
	else
		return ;
}
