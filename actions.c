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

void    sa(t_stack *a)
{
    int top_nbr;

    top_nbr = *(int *) ft_lstlast(a)->content;
    while (a && a->next && a->next->next)
        a = a->next;
    
    ft_printf("sa\n");
}

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
void    sb(t_stack *b)
{
    int top_nbr;

    top_nbr = *(int *) ft_lstlast(b)->content;
    while (b && b->next && b->next->next)
        b = b->next;
    *(int *)b->next->data = *(int *)b->data;
    *(int *)b->data = top_nbr;
    ft_printf("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}

void    pa(t_stack *a, t_stack *b)
{
    int top_nbr_b;
    
    if(!b)
        return ;
    top_nbr_b = *(int *) ft_lstlast(b)->content;

}
*/