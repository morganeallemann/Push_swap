/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	function_1(t_stack *a)
{
	ra(a);
	sa(a);
}

void	function_2(t_stack *a)
{
	rra(a);
	sa(a);
}

/* 
	Fonction permettant de trier les elements quand il y en que 3 uniquement.
	On force le tri dans tout les cas de figure possible. La stack b n'a pas
	besoin d'etre utilisee avec 3 nombres.
*/
void	sort_3(t_stack *a)
{
	int	node_1;
	int	node_2;
	int	node_3;

	node_1 = *(int *)a->content;
	node_2 = *(int *)a->next->content;
	node_3 = *(int *)a->next->next->content;
	if (!(in_order(a)))
	{
		if ((node_1 < node_2) && (node_2 < node_3))
			function_1(a);
		else if ((node_1 > node_2) && (node_3 > node_1))
			ra(a);
		else if ((node_2 > node_1) && (node_1 > node_3))
			function_2(a);
		else if ((node_1 > node_3) && (node_3 > node_2))
			sa(a);
		else if ((node_2 > node_3) && (node_3 > node_1))
			rra(a);
	}
	else
		return ;
}
