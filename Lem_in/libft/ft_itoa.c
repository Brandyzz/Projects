/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:54:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:54:35 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	n_length(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	int	n_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	int		len;

	sign = n_sign(n);
	len = n_length(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(ret = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	else
	{
		ret = ret + len + sign;
		*ret = '\0';
		if (!n)
			*--ret = '0';
		while (n != 0)
		{
			*--ret = ABS(n % 10) + '0';
			n = n / 10;
		}
		if (sign)
			*--ret = '-';
	}
	return (ret);
}
