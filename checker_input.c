/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction atoi modifiee pour verifier que les int min et max soit ok. */
int	ft_atoi_ps(char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign > INTMAX || res * sign < INTMIN)
		ft_error();
	return (res * sign);
}

/*
	Fonction qui va permettre de verifier que les elements entre soient bien
	uniquement des nombres entier positif ou negatifs. Elle renvoi 1 en cas 
	d'erreur. 
*/
int	check_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == '+'
				|| str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

/*
	Fonction qui va permettre de verifier que le nombre ne comporte pas plus
	d'un seul signe et renvoie 1 en cas d'erreur.
*/
int	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] == '+' || str[i + 1] == '-')
				return (1);
			if (str[i + 1] == '\0' || str[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

/* 
	Fonction qui renvoie vers une fonction qui check si les elements
	entre sont bien des nombre. Puis si ok elle va renvoyer vers la
	fonction check_sign qui verifiera que il y a au max. 1 signe.
*/
int	valid_input(char *str)
{
	if (check_nb(str) != 0)
		return (1);
	if (check_sign(str) != 0)
		return (1);
	return (0);
}

/*
	Fonction qui va verifier qu'il n'y a aucune double entree, elle 
	renvoi 1 en cas d'erreur.
*/
int	check_double(t_input *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->nb_elem)
	{
		j = i + 1;
		while (j < parse->nb_elem)
		{
			if (parse->array[i] == parse->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
