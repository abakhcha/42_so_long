/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zed.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:05:18 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/31 13:23:56 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	theexit(t_mlx *mlx)
{
	printstrnum("mouvement number : ", mlx->player->m);
	ft_putstr("******* << you win >> *******\n");
	exit(0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (s[i])
	{
		i++;
	}
	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	while (s[j])
	{
		p[j] = s[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

void	flodfi(char **map, int x, int y)
{
	if ((map[x][y] && map[x][y] == '1') || map[x][y] == 'E'
		|| y > line_size(map) || x > lines_number(map) || y < 0 || x < 0)
		return ;
	map[x][y] = '1';
	flodfi(map, x, y + 1);
	flodfi(map, x + 1, y);
	flodfi(map, x - 1, y);
	flodfi(map, x, y - 1);
}
