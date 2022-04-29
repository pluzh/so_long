/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:20 by lmichel           #+#    #+#             */
/*   Updated: 2021/10/20 13:46:22 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	ret = (char *)malloc((1 + len) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && s[i])
	{
		ret[i] = s[(size_t)start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_gnl(char *str, char buf)
{
	int		i;
	char	*str1;

	str1 = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!str1)
	{
		write(2, "Error\nMalloc error!\n", 20);
		exit(1);
	}
	i = -1;
	while (str[++i])
		str1[i] = str[i];
	str1[i++] = buf;
	if (buf != '\0')
		str1[i] = '\0';
	return (str1);
}
