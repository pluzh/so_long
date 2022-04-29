/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:20 by lmichel           #+#    #+#             */
/*   Updated: 2021/10/20 13:46:22 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		r;
	char	c;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	r = read(fd, &c, 1);
	while (r)
	{
		if (r == -1)
		{
			write(2, "Error\nNo map specified!\n", 24);
			exit(1);
		}
		tmp = line;
		line = ft_strjoin_gnl(line, c);
		i++;
		if (i > 1)
			free(tmp);
		r = read(fd, &c, 1);
	}
	return (line);
}
