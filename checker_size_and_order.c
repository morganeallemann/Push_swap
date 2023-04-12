/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_size_and_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int in_order(t_stack *a)
{
    while (a->next != NULL)
    {
        if (*(int *)a->content < *(int *)a->next->content)
            return (0);
        a = a->next;
    }
    return (1);
}

void    size_checker(t_stack *a, t_stack *b)
{
    int len;

    len = ft_lstsize(a);
    b = (void *)b;
    if (len == 1)
        return ;
    if (len == 2)
    {
        if (!(in_order(a)))
            sa(a);
    }
    else if (len == 3)
        sort_3(a);
    /*else if (len == 4)
        sort_4(a, b);
    else if (len == 5)
        sort_5(a, b);
    else
        big_sort(a, b, size)
    */
}