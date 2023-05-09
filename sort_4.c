/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
	Fonction permettant de trouver le chiffre indiquer sur la variable 
	(nb_to_find). On boucle tant que l'on est dans a et on compare le contenu
	de chaque node avec le chiffre a trouver. Si on ne le trouve pas c'est 
	qu'une erreur est survenue. 
*/
int	find_nb(t_stack *a, int nb_to_find)
{
	int	i;

	i = 0;
	while (a)
	{
		if (*(int *)a->content == nb_to_find)
			return (i);
		a = a->next;
		i++;
	}
	ft_error();
	return (1);
}

/*
	Fonction permettant de mettre le chiffre 0 en 3e position en
	fonction de la position ou il se trouve initialement puis l'envoyer sur
	la stack b. 
*/
void	put_last_pos(t_stack *a, t_stack **b, int index)
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
	Fonction qui permettera de remettre dans l'ordre une liste de 4
	elements. On declare une variable int qui va trouver la position du
	chiffre 0 dans la liste. On va ensuite envoier la fonction put_last_pos
	et trier les 3 chiffre de la stack a et remettre ensuite le 0 au 
	debut de la stack a. 
*/
void	sort_4(t_stack *a, t_stack *b)
{
	int	nb_0;

	if (!(in_order(a)))
	{
		nb_0 = find_nb(a, 0);
		put_last_pos(a, &b, nb_0);
		sort_3(a);
		pa(&a, &b);
	}
	else
		return ;
}
