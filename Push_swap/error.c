/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:21 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:51:05 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	error_duplicate(int *nbrs, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac && nbrs[i] != nbrs[j])
			j++;
		if (j != ac)
			return (1);
		i++;
	}
	return (0);
}

static int	error_not_int(char *av, int nb)
{
	int	strlen;
	int	nblen;

	strlen = ft_strlen(av);
	if ((nb > 0 && av[0] == '-') || (nb < 0 && av[0] != '-'))
		return (1);
	nblen = (nb > 0 ? 0 : 1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen != strlen ? 1 : 0);
}

static int	error_digit(char *nbr)
{
	int	er;
	int	i;

	i = (nbr[0] == '-' ? 1 : 0);
	er = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			er++;
		i++;
	}
	return (er);
}

int			error_nbr(int ac, char **av)
{
	int	i;
	int	er;
	int	nbrs[ac];

	i = 0;
	er = 0;
	while (av[i])
	{
		nbrs[i] = ft_atoi(av[i]);
		if (error_not_int(av[i], nbrs[i]) || error_digit(av[i]))
			er++;
		i++;
	}
	er += error_duplicate(nbrs, ac);
	er += error_case(av);
	if (er != 0)
	{
		ft_putstr_fd("Error\n", 2);
		er++;
	}
	return (er);
}

int			error_str(char *str)
{
	int	er;

	er = 0;
	if (str == NULL)
		return (1);
	if (ft_strlen(str) == 2 && str[0] == 's'
				&& (str[1] == 'a' || str[1] == 'b'
				|| str[1] == 's'))
		er++;
	if (ft_strlen(str) == 2 && str[0] == 'p'
				&& (str[1] == 'a' || str[1] == 'b'))
		er++;
	if (str[0] == 'r')
	{
		if (ft_strlen(str) == 2 &&
				(str[1] == 'a' || str[1] == 'b' || str[1] == 'r'))
			er++;
		if (ft_strlen(str) == 3 && str[1] == 'r' &&
				(str[1] == 'a' || str[1] == 'b' || str[1] == 'r'))
			er++;
	}
	if (er == 0 && str[0] != '\0')
		ft_putstr_fd("Error\n", 2);
	return (er);
}
