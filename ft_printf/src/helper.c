/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:32:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 15:08:39 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_with_flag(char *str, int w, int p, char c)
{
	int	i;

	i = 0;
	if (p == -1)
	{
		i += ft_putstr(str);
		while (i < w)
			i += ft_putchar(c);
	}
	else
	{
		while (i < p && str[i])
			ft_putchar(str[i++]);
		while (i < w)
			i += ft_putchar(c);
	}
	return (i);
}

int		print_without_flag(char *str, int w, int p, char c)
{
	int	len;
	int	l;
	int	i;
	int j;

	len = ft_strlen(str);
	l = (p == -1) ? len : p;
	if (p != -1)
		l = (len > p) ? p : len;
	i = 0;
	while (w - i > l)
		i += ft_putchar(c);
	j = -1;
	while (str[++j] && j < l)
		i = i + ft_putchar(str[j]);
	return (i);
}

size_t	cast_to_flag(size_t n, t_token *tok)
{
	if ((tok->flags & F_HH) == F_HH)
		return ((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		return ((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		return ((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		return ((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		return ((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		return ((size_t)n);
	return ((unsigned int)n);
}

int		check_for_kostyl(long double n)
{
	if (n == 1 / 0.0 || n == -1 / 0.0)
		return (1);
	else if (n != n)
		return (1);
	else if (!n)
		return (1);
	else
		return (0);
}

int		kostyl(long double n, t_token *tok)
{
	if (n == 1.0 / 0.0)
		return (print_string("inf", tok));
	if (n == -1.0 / 0.0)
		return (print_string("-inf", tok));
	if (n != n)
		return (print_string("nan", tok));
	if (!n)
		return (print_double(0.0, tok));
	return (0);
}
