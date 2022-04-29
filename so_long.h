/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/12/08 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	int		map_width;
	int		map_height;
	char	**map;
	int		coll;
	int		e;
	int		p;
	int		steps;
	int		x;
	int		y;
}	t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	so_long(char **argv, t_game *game);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_put_error_walls(void);
void	ft_check_walls(char **map);
void	ft_put_img(char c, int i, int j, t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_steps(t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);

#endif
