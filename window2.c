/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:08:39 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/17 16:02:37 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_loadhouse_image(void *mlx, void *win, int *l, int *j)
{
	t_image	house;

	house.relative_path = "img/house.xpm";
	house.img = mlx_xpm_file_to_image(mlx, house.relative_path,
			&house.img_width, &house.img_height);
	if (!house.img || !house.relative_path)
		error_print("Error\nimage problem !!\n");
	mlx_put_image_to_window(mlx, win, house.img, *l, *j);
}

void	ft_lodwalls_image(void *mlx, void *win, int *l, int *j)
{
	t_image	walls;

	walls.relative_path = "img/walls.xpm";
	walls.img = mlx_xpm_file_to_image(mlx, walls.relative_path,
			&walls.img_width, &walls.img_height);
	if (!walls.img || !walls.relative_path)
		error_print("Error\nimage problem !!\n");
	mlx_put_image_to_window(mlx, win, walls.img, *l, *j);
}

void	ft_lodcollect_image(void *mlx, void *win, int *l, int *j)
{
	t_image	collect;

	collect.relative_path = "img/collect.xpm";
	collect.img = mlx_xpm_file_to_image(mlx, collect.relative_path,
			&collect.img_width, &collect.img_height);
	if (!collect.img || !collect.relative_path)
		error_print("Error\nimage problem !!\n");
	mlx_put_image_to_window(mlx, win, collect.img, *l, *j);
}

void	ft_lodlard_image(t_mlx *mlx, int *l, int *j)
{
	t_image	lard;

	lard.relative_path = "img/lard.xpm";
	lard.img = mlx_xpm_file_to_image(mlx->mlx, lard.relative_path,
			&lard.img_width, &lard.img_height);
	if (!lard.img || !lard.relative_path)
		error_print("Error\nimage problem !!\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, lard.img, *l, *j);
}
