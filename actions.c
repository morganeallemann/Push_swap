/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
	Fonction qui intervertit les 2 premiers éléments au sommet de la pile a.
	On trouve le dernier element de la liste puis alons se placer a l'avant
	dernier node et on swap le dernier et l'avant dernier. 
*/
void	sa(t_stack *a)
{
	int	top_nbr;

	top_nbr = *(int *) ft_lstlast(a)->content;
	while (a && a->next && a->next->next)
		a = a->next;
	*(int *)a->next->content = *(int *)a->content;
	*(int *)a->content = top_nbr;
	ft_printf("sa\n");
}

/*
	Fonction qui décale d’une position vers le haut tous les élements de la 
	pile a. Le premier élément devient le dernier.
*/
void	ra(t_stack *a)
{
	int		temp;
	int		temp_pres;

	temp_pres = *(int *) ft_lstlast(a)->content;
	while (a)
	{	
		temp = *(int *)(a->content);
		*(int *)(a->content) = temp_pres;
		temp_pres = temp;
		a = a->next;
	}
	ft_printf("ra\n");
}

/*
	Fonction qui décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.
*/
void	rra(t_stack *a)
{
	int		temp;

	temp = *(int *) a->content;
	while (a->next)
	{
		*(int *)(a->content) = *(int *)(a->next->content);
		a = a->next;
	}
	*(int *)a->content = temp;
	ft_printf("rra\n");
}

/*
	Fonction qui prend le premier élément au sommet de a et le met sur b.
*/
void	pb(t_stack **a, t_stack **b)
{
	int		*temp_ptr;
	t_stack	*copy;

	if (!a || !*a)
		return ;
	temp_ptr = malloc(sizeof(int));
	if (!temp_ptr)
		return ;
	*temp_ptr = *(int *)ft_lstlast(*a)->content;
	ft_lstadd_back(b, ft_lstnew((void *)temp_ptr));
	copy = *a;
	while (copy->next && copy->next->next)
		copy = copy->next;
	ft_lstdelone(ft_lstlast(*a), free);
	copy->next = NULL;
	ft_putendl_fd("pb", 1);
}

/*
	Fonction qui prend le premier élément au sommet de b et le met sur a.
*/
void	pa(t_stack **a, t_stack **b)
{	
	int		*temp_ptr;
	int		remove_first;
	t_stack	*copy;

	remove_first = 0;
	if (!b || !*b)
		return ;
	temp_ptr = malloc(sizeof(int));
	if (!temp_ptr)
		return ;
	*temp_ptr = *(int *)ft_lstlast(*b)->content;
	ft_lstadd_back(a, ft_lstnew((void *)temp_ptr));
	copy = *b;
	while (copy->next && copy->next->next)
		copy = copy->next;
	if (ft_lstsize(*b) == 1)
		remove_first = 1;
	ft_lstdelone(ft_lstlast(*b), free);
	if (remove_first == 1)
		*b = NULL;
	else
		copy->next = NULL;
	ft_putendl_fd("pa", 1);
}
