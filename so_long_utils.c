/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/12/08 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_error_walls(void)
{
	write(2, "Error\nInvalid walls!\n", 21);
	exit(EXIT_SUCCESS);
}

void	ft_check_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][j])
		if (map[0][j++] != '1')
			ft_put_error_walls();
	while (map[i])
		if (map[i++][0] != '1')
			ft_put_error_walls();
	i--;
	j = 0;
	while (map[i][j])
		if (map[i][j++] != '1')
			ft_put_error_walls();
	j--;
	i = 0;
	while (map[i])
		if (map[i++][j] != '1')
			ft_put_error_walls();
}

void	ft_put_img(char c, int ii, int j, t_game *g)
{
	t_data	i;
	char	*p;
	int		i_w;
	int		i_h;

	if (c == 'P')
		p = "img/con.xpm";
	else if (c == 'E')
		p = "img/door.xpm";
	else if (c == '1')
		p = "img/wall.xpm";
	else if (c == 'C')
		p = "img/carrot.xpm";
	else
		p = "img/zero.xpm";
	i.img = mlx_xpm_file_to_image(g->mlx.mlx, p, &i_w, &i_h);
	i_w = j * 32;
	i_h = ii * 32;
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.mlx_win, i.img, i_w, i_h);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_steps(t_game *game)
{
	t_data	i;
	char	*p;
	int		i_w;
	int		i_h;
	char	*str;

	game->steps++;
	p = "img/wall.xpm";
	str = ft_itoa(game->steps);
	i.img = mlx_xpm_file_to_image(game->mlx.mlx, p, &i_w, &i_h);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, i.img, 0, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, i.img, 32, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, i.img, 64, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 8, 8, 0xffe4b5, "steps:");
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 50, 8, 0xffe4b5, str);
	ft_putstr_fd("Current number of movements: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
	free(str);
}
