/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction permettant de free les stack a et b. */
void	free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
}

/*
	Fonction permettant de free nos variables str_tab et array une fois que 
	nous avons fini de les utiliser pour le parsing.  
*/
void	ft_free_parse(t_input *parse)
{
	int	i;

	i = 0;
	free(parse->array);
	if (parse->str_tab != NULL)
	{
		while (parse->str_tab[i])
		{
			free(parse->str_tab[i]);
			i++;
		}
		free(parse->str_tab);
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
