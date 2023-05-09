/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Fonction permettant de creer la liste chainee en mettant les nombres 
	stocke dans index dans le contenu de chaque node de la liste chainee.
*/
t_stack	*create_stack(t_input *parse, int **index)
{
	int		i;
	t_stack	*a;
	t_list	*tmp;

	i = 0;
	a = NULL;
	while (i < parse->nb_elem)
	{
		tmp = ft_lstnew(index[i]);
		ft_lstadd_front(&a, tmp);
		i++;
	}
	return (a);
}

/*
	Fonction qui va permettre d'initialiser la stack a. On va utiliser un 
	index dans lequel on stockera nos nombres. La variable larger va 
	s'incrementer chaque fois que le nombre comparer sera plus grand. Ainsi
	on rentrera dans l'index des nombres simplifiee du plus grand au plus petit. 
	ex: 33 98 100 1 deviendra -> 1 2 3 0.
*/
t_stack	*new_stack(t_input *parse)
{
	int		i;
	int		j;
	int		larger;
	int		**index;
	t_stack	*a;

	i = -1;
	a = NULL;
	index = malloc(sizeof(int *) * parse->nb_elem);
	if (!index)
		exit(1);
	while (++i < parse->nb_elem)
	{
		j = -1;
		larger = 0;
		while (++j < parse->nb_elem)
			if (parse->array[i] > parse->array[j])
				larger++;
		index[i] = malloc(sizeof(int));
		*index[i] = larger;
	}
	a = create_stack(parse, index);
	free(index);
	return (a);
}
