/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          :+:         :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/12/08 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (game->x != -1 && game->y != -1)
	{
		if (keycode == 13)
			ft_up(game);
		if (keycode == 0)
			ft_left(game);
		if (keycode == 1)
			ft_down(game);
		if (keycode == 2)
			ft_right(game);
	}
	return (0);
}

int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_init_map(t_game *game)
{
	int		i;
	int		j;
	int		h;
	int		w;

	i = 0;
	game->mlx.mlx = mlx_init();
	w = game->map_width * 32;
	h = (game->map_height) * 32;
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, w, h, "So_long");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_img(game->map[i][j], i, j, game);
			j++;
		}
		i++;
	}
	game->steps = 0;
	mlx_key_hook(game->mlx.mlx_win, key_hook, &game->mlx);
	mlx_hook(game->mlx.mlx_win, 17, 1L << 0, ft_close, &game->mlx);
	mlx_loop(game->mlx.mlx);
	ft_free_map(game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			if (argv[1][i++] == '.')
				if (argv[1][i] == 'b' && argv[1][i + 1] == 'e'
					&& argv[1][i + 2] == 'r')
					check++;
		if (!check)
		{
			write(2, "Error\nFile with invalid extension!\n", 35);
			exit(EXIT_SUCCESS);
		}
		so_long(argv, &game);
		ft_init_map(&game);
	}
	else
		write(2, "Error\nusage:	./so_long *.ber\n", 29);
	return (0);
}
