/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3(t_stack *a)
{
    if (!(in_order(a)))
    {
        if ((*(int *)a->content > *(int *)a->next->content) && (*(int *)a->content < *(int *)a->next->next->content))
            sa(a);
        else if (*(int *)a->content < *(int *)a->next->content)
        {
            sa(a);
            ra(a);
        }    
        else if (*(int *)a->content > *(int *)a->next->content && (*(int *)a->next->content < *(int *)a->next->next->content))
            ra(a);
        else if (*(int *)a->content > *(int *)a->next->content && (*(int *)a->next->content > *(int *)a->next->next->content))
        {
            ra(a);
            sa(a);
        }
    else
        return ;
    }    
}

void    sort_4(t_stack *a)
{
    
}