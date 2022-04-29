/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/12/08 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ecp(char ch, t_game *game, int j, int i)
{
	if (ch == 'E')
		game->e++;
	else if (ch == 'C')
		game->coll++;
	else if (ch == 'P')
	{
		game->p++;
		game->x = j;
		game->y = i;
	}
	else if (ch != '0' && ch != '1')
	{
		write(2, "Error\nFile contains different", 29);
		write(2, " character than 1, 0, P, E or C\n", 32);
		exit(EXIT_SUCCESS);
	}
}

void	ft_check_char(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 1;
	game->e = 0;
	game->p = 0;
	game->coll = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			ft_check_ecp(map[i][j], game, j, i);
			j++;
		}
		i++;
	}
	if (game->e == 0 || game->p != 1 || game->coll == 0)
	{
		write(2, "Error\nFile is missing P, E or C\n", 32);
		exit(EXIT_SUCCESS);
	}
	ft_check_walls(map);
}

void	ft_check_width(t_game *game, int width)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != width)
		{
			write(2, "Error\nInvalid map!\n", 19);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	int	i;
	int	j;
	int	high;
	int	width;

	high = 0;
	i = 0;
	while (game->map[i++])
		high++;
	game->map_height = high;
	if ((high) < 2)
	{
		write(2, "Error\nInvalid map!\n", 19);
		exit(EXIT_SUCCESS);
	}
	j = 0;
	width = 0;
	while (game->map[0][j++])
		width++;
	game->map_width = width;
	ft_check_width(game, width);
	ft_check_char(game->map, game);
}

void	so_long(char **argv, t_game *game)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldn't open file!\n", 26);
		exit(EXIT_SUCCESS);
	}
	tmp = get_next_line(fd);
	game->map = ft_split(tmp, '\n');
	ft_check_map(game);
	free(tmp);
	close(fd);
}
