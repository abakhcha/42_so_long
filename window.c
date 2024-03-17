/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:44:03 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/17 16:13:09 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_lodcharac_image(t_mlx *mlx, int *l, int *j)
{
	t_image	charac;

	charac.relative_path = "img/charac.xpm";
	charac.img = mlx_xpm_file_to_image(mlx->mlx, charac.relative_path,
			&charac.img_width, &charac.img_height);
	if (!charac.img || !charac.relative_path)
		error_print("Error\nimage problem !!\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, charac.img, *l, *j);
}

void	ft_drawmap(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			x = i * 90;
			y = j * 90;
			if (map[i][j] == '1')
				ft_lodwalls_image(mlx->mlx, mlx->win, &y, &x);
			else if (map[i][j] == 'E')
				ft_loadhouse_image(mlx->mlx, mlx->win, &y, &x);
			else if (map[i][j] == 'P')
				ft_lodcharac_image(mlx, &y, &x);
			else if (map[i][j] == 'C')
				ft_lodcollect_image(mlx->mlx, mlx->win, &y, &x);
			else if (map[i][j] == '0')
				ft_lodlard_image(mlx, &y, &x);
		}
	}
}

int	keys(int key, t_mlx *mlx)
{
	int	i;

	i = 0;
	if (key == 53)
		destroy(mlx);
	else if (key == 126 || key == 13)
		move_up(mlx);
	else if (key == 1 || key == 125)
		move_down(mlx);
	else if (key == 0 || key == 123)
		move_left(mlx);
	else if (key == 2 || key == 124)
		move_right(mlx);
	return (0);
}

void	ft_putmap(char **map, t_mlx *mlx)
{
	int	l;
	int	h;

	l = line_size(map) * 90;
	h = lines_number(map) * 90;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, l, h, "Solong");
	ft_drawmap(map, mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
}
