/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
    Fonction permettant de free nos variables str_tab et array une fois que 
    nous avons fini de les utiliser pour le parsing.  
*/
void    ft_free_parse(t_input *parse)
{
    int i;

    i = 0;
    while (parse->str_tab)
    {
        while (parse->str_tab[i])
        {
            free(parse->str_tab[i]);
            i++;
        }
        free(parse->str_tab);
    }
    free(parse->array);
}

/*
    Fonction qui va permettre d'initialiser la string rentree en parametre.
    On va dabord renvoyer la string vers la fonction valid_input qui verifie
    que les elements sont correct. Ensuite elle alloue la memoire pour le tabl.
    de INT et va convertir les char en INT et les stocker dans *array.
*/
void    ft_init(t_input *parse)
{
    int i;

    i = 0;
    while (parse->str_tab[i])
    {
        if (valid_input(parse->str_tab[i]) != 0)
        {
            printf("ERROR\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    parse->array = malloc(sizeof(int) * parse->nb_elem);
    while (parse->str_tab[i])
    {
        parse->array[i] = ft_atoi(parse->str_tab[i]);
        ft_printf("%d\n", parse->array[i]);
        i++;
    }

}

/*
    Fonction qui permet de faire le parsing de la string rentree en parametre. 
    Si les parametre on etait entree en une seul string on va faire appel a 
    split afin de separer chaque nombre. 
    Si les nombres ont ete envoyer en different char on va initialiser notre 
    nb_ele avec le nombre d'argument entre et les valeurs. 
    Les deux fonctions renverront vers la fonction init. 
    Ensuite on enverra la fonction new_stack qui permettra de creer la 
    premiere stack et ensuite on va free. La fonction va retourner la stack a. 
*/

t_stack    *ft_parse(int ac, char **av)
{
    t_input parse;
    t_stack *a;      

    parse.nb_elem = 0;
    if (ac == 2)
    {
        parse.str_tab = ft_split(av[1], ' ');
        while (parse.str_tab[parse.nb_elem])
            parse.nb_elem++;
        ft_init(&parse);
    }
    else if (ac > 2)
    {
        parse.nb_elem = ac - 1;
        parse.str_tab = av + 1;
        ft_init(&parse);
    }
    else
        return (0);
    a = new_stack(&parse);
    free (parse.array);
    return (a);
}



