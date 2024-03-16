/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zed.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:05:18 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/16 12:42:52 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
