/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:49:46 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/29 23:24:49 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freedoubleptr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	checkkk(int ac, char **av)
{
	if (ac >= 3)
		error_print("Error\nyou have more than 1 argument\n");
	if (ac != 2)
		error_print("Error\nempty argument\n");
	if (checkextention(av) == -1)
		error_print("Error\nverify extention \n");
}

char	**doublepointercopy(char **map)
{
	int		i;
	char	**test;

	i = 0;
	while (map[i])
	{
		i++;
	}
	test = (char **)ft_calloc(i, strlen(map[0]));
	i = 0;
	while (map[i])
	{
		test[i] = ft_strdup(map[i]);
		i++;
	}
	test[i] = 0;
	return (test);
}

int	main(int ac, char **av)
{
	int			fd;
	char		**map;
	char		**mapcpy;
	t_player	player;
	t_mlx		mlx;

	checkkk(ac, av);
	fd = open(av[1], O_RDWR);
	if (fd == -1 || !fd)
		error_print("Error\ncan not open the file");
	map = map_to_doublepointer(fd);
	mlx.map = map;
	mapcpy = doublepointercopy(map);
	chaeckmap(av, map);
	player.x = xposition(map);
	player.y = yposition(map);
	mlx.player = &player;
	flodfil(mapcpy, player.x, player.y);
	checkacsess(mapcpy, map, player);
	player.m = 1;
	ft_putmap(map, &mlx);
	freedoubleptr(mapcpy);
	freedoubleptr(mlx.map);
	return (0);
}
