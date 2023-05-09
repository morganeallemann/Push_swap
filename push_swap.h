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
	int		nb_elem;
	int		*array;
	char	**str_tab;
}		t_input;

typedef t_list	t_stack;

/* Fonction permettant le parsing et l'initialisation de la stack. */
t_stack	*ft_parse(int ac, char **av, t_input *parse);
t_stack	*new_stack(t_input *parse);
void	ft_free_array(t_input *parse);

/* Fonction permettant de gerer les erreurs et free les allocations. */
void	ft_free_parse(t_input *parse);
void	free_stack(t_stack **a, t_stack **b);
void	ft_error(void);

/* Fonctions permettant de verifier les elements entres en parametres. */
int		check_double(t_input *parse);
int		valid_input(char *str);
int		ft_atoi_ps(char *str);

/* Fonction permettant de trier les elements de la liste. */
void	size_checker(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	big_sort(t_stack *a, t_stack *b, int nb_element);
int		find_nb(t_stack *a, int nb_to_find);
int		in_order(t_stack *a);

/* Fonctions permettant d'effectuer les mouvements des piles a et b. */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

#endif 