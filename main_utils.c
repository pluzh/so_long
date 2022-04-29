/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/12/08 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_game(t_game *game, int y, int x)
{
	game->map[y][x] = '0';
	put_steps(game);
	exit (1);
}

void	ft_up(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[--y][x] && game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y + 1][x] = '0';
			game->coll--;
		}
		else if (game->map[y][x] == 'E' && game->coll == 0)
			ft_exit_game(game, y + 1, x);
		else if (game->map[y][x] != 'E')
			game->map[y + 1][x] = game->map[y][x];
		if (game->map[y][x] != 'E')
		{
			game->map[y][x] = 'P';
			game->y = y;
		}
		ft_put_img(game->map[y][x], y, x, game);
		ft_put_img(game->map[y + 1][x], y + 1, x, game);
		put_steps(game);
	}
}

void	ft_down(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[++y][x] && game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->coll--;
			game->map[y - 1][x] = '0';
		}
		else if (game->map[y][x] == 'E' && game->coll == 0)
			ft_exit_game(game, y - 1, x);
		else if (game->map[y][x] != 'E')
			game->map[y - 1][x] = game->map[y][x];
		if (game->map[y][x] != 'E')
		{
			game->map[y][x] = 'P';
			game->y = y;
		}
		ft_put_img(game->map[y][x], y, x, game);
		ft_put_img(game->map[y - 1][x], y - 1, x, game);
		put_steps(game);
	}
}

void	ft_left(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[y][--x] && game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x + 1] = '0';
			game->coll--;
		}
		else if (game->map[y][x] == 'E' && game->coll == 0)
			ft_exit_game(game, y, x + 1);
		else if (game->map[y][x] != 'E')
			game->map[y][x + 1] = game->map[y][x];
		if (game->map[y][x] != 'E')
		{
			game->map[y][x] = 'P';
			game->x = x;
		}
		ft_put_img(game->map[y][x], y, x, game);
		ft_put_img(game->map[y][x + 1], y, x + 1, game);
		put_steps(game);
	}
}

void	ft_right(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[y][++x] && game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->coll--;
			game->map[y][x - 1] = '0';
		}
		else if (game->map[y][x] == 'E' && game->coll == 0)
			ft_exit_game(game, y, x - 1);
		else if (game->map[y][x] != 'E')
			game->map[y][x - 1] = game->map[y][x];
		if (game->map[y][x] != 'E')
		{
			game->map[y][x] = 'P';
			game->x = x;
		}
		ft_put_img(game->map[y][x], y, x, game);
		ft_put_img(game->map[y][x - 1], y, x - 1, game);
		put_steps(game);
	}
}
