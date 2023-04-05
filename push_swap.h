/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INTMAX +2147483647
# define INTMIN -2147483648

typedef struct s_input
{
    int             nb_elem;
    int             *array;
    char            **str_tab;
}   t_input;

typedef t_list  t_stack;

t_stack    *ft_parse(int ac, char **av);
int        valid_input(char *str);

/* Fonctions permettant d'effectuer les mouvements des piles a et b. */
void    sa(t_stack *a);
void    sb(t_stack *b);


#endif 