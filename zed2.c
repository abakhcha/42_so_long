/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zed2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:54:58 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/27 16:49:56 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkacsess(char **mapcpy, char **map, t_player player)
{
	char	**map2;

	map2 = doublepointercopy(map);
	flodfi(map2, player.x, player.y);
	if (epc2(mapcpy) == -1 || epc1(map2) == -1)
		error_print("Error\nplayer can not reach one ore more than element\n");
	freedoubleptr(map2);
}
