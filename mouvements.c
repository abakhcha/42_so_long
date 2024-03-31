/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:08:21 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/31 14:51:53 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->map[mlx->player->x - 1][mlx->player->y] == 'E')
	{
		if (collectib(mlx->map) == 0)
			theexit(mlx);
		if (collectib(mlx->map) > 0)
			return ;
	}
	if (mlx->map[mlx->player->x - 1][mlx->player->y] != '1')
	{
		mlx->map[mlx->player->x][mlx->player->y] = '0';
		x = mlx->player->x * 90;
		y = mlx->player->y * 90;
		ft_lodlard_image(mlx, &y, &x);
		mlx->player->x--;
		x = mlx->player->x * 90;
		ft_lodcharac_image(mlx, &y, &x);
		mlx->map[mlx->player->x][mlx->player->y] = 'P';
		printstrnum("mouvement number : ", mlx->player->m);
		mlx->player->m++;
	}
}

void	move_down(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->map[mlx->player->x + 1][mlx->player->y] == 'E')
	{
		if (collectib(mlx->map) == 0)
			theexit(mlx);
		if (collectib(mlx->map) > 0)
			return ;
	}
	if (mlx->map[mlx->player->x + 1][mlx->player->y] != '1')
	{
		mlx->map[mlx->player->x][mlx->player->y] = '0';
		x = mlx->player->x * 90;
		y = mlx->player->y * 90;
		ft_lodlard_image(mlx, &y, &x);
		mlx->player->x++;
		x = mlx->player->x * 90;
		ft_lodcharac_image(mlx, &y, &x);
		mlx->map[mlx->player->x][mlx->player->y] = 'P';
		printstrnum("mouvement number : ", mlx->player->m);
		mlx->player->m++;
	}
}

void	move_right(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->map[mlx->player->x][mlx->player->y + 1] == 'E')
	{
		if (collectib(mlx->map) == 0)
			theexit(mlx);
		if (collectib(mlx->map) > 0)
			return ;
	}
	if (mlx->map[mlx->player->x][mlx->player->y + 1] != '1')
	{
		mlx->map[mlx->player->x][mlx->player->y] = '0';
		x = mlx->player->x * 90;
		y = mlx->player->y * 90;
		ft_lodlard_image(mlx, &y, &x);
		mlx->player->y++;
		y = mlx->player->y * 90;
		ft_lodcharac_image(mlx, &y, &x);
		mlx->map[mlx->player->x][mlx->player->y] = 'P';
		printstrnum("mouvement number : ", mlx->player->m);
		mlx->player->m++;
	}
}

void	move_left(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->map[mlx->player->x][mlx->player->y - 1] == 'E')
	{
		if (collectib(mlx->map) == 0)
			theexit(mlx);
		if (collectib(mlx->map) > 0)
			return ;
	}
	if (mlx->map[mlx->player->x][mlx->player->y - 1] != '1')
	{
		mlx->map[mlx->player->x][mlx->player->y] = '0';
		x = mlx->player->x * 90;
		y = mlx->player->y * 90;
		ft_lodlard_image(mlx, &y, &x);
		mlx->player->y--;
		y = mlx->player->y * 90;
		ft_lodcharac_image(mlx, &y, &x);
		mlx->map[mlx->player->x][mlx->player->y] = 'P';
		printstrnum("mouvement number : ", mlx->player->m);
		mlx->player->m++;
	}
}
