/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:58:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:58:19 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*trim;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	if (i == len)
		return ("");
	while (s[len - 1] == '\t' || s[len - 1] == ' ' || s[len - 1] == '\n')
		len--;
	if ((trim = ft_strnew(len - i)) == NULL)
		return (NULL);
	while (s[i] && i < len)
		trim[j++] = s[i++];
	trim[j] = '\0';
	return (trim);
}
