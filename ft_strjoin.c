/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:56:20 by lmichel           #+#    #+#             */
/*   Updated: 2021/10/08 13:56:22 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (!(s1 && s2))
		return (NULL);
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}
