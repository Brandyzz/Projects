/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:41:34 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 12:37:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	return (int)((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}
