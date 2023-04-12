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

t_stack *create_stack(t_input *parse, int **index)
{
    int i;
    t_stack *a;

    i = 0;
    a = NULL;
    while (i < parse->nb_elem)
    {
        ft_lstadd_front(&a, ft_lstnew(index[i]));
        i++;
    }
    return (a);
}

t_stack *new_stack(t_input *parse)
{
    int i;
    int j;
    int larger;
    int **index;
    t_stack *a;

    i = 0;
    a = NULL;
    index = malloc(sizeof(int *) * parse->nb_elem);
    if (!index)
    {
        ft_free_parse(parse);
        exit(EXIT_FAILURE);
    }
    while (i < parse->nb_elem)
    {
        j = 0;
        larger = 0;
        while (j < parse->nb_elem)
        {
            if (parse->array[i] > parse->array[j])
                larger++;
            j++;
        }
        index[i] = malloc(sizeof(int));
        *index[i] = larger;
        i++;
    }
    a = create_stack(parse, index);
    free(index);
    return (a);
}