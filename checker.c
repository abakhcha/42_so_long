/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:26:27 by abakhcha          #+#    #+#             */
/*   Updated: 2024/03/17 16:15:20 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checkextention(char **av)
{
	char	*p;

	if (ft_strlen(av[1]) == 4)
		return (-1);
	p = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if (ft_strncmp(p, ".ber", 4) == 0)
		return (free(p), 1);
	else
		return (free(p), -1);
}

void	error_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

char	**map_to_doublepointer(int fd)
{
	char	*s1;
	char	*l;
	char	**map;
	int		i;

	l = get_next_line(fd);
	if (l == NULL)
		error_print("Error\nempty file \n");
	s1 = ft_calloc(1, 1);
	while (l != NULL)
	{
		s1 = str_join(s1, l);
		free(l);
		l = get_next_line(fd);
	}
	i = check_empty_line(s1);
	if (i == -1)
		error_print("Error\nempty line \n");
	map = ft_split(s1, '\n');
	free(s1);
	return (map);
}

void	chaeckmap(char **av, char **map)
{
	if (!map || map[0] == '\0')
		error_print("error !!\n");
	if (av[1][0] == 0)
		error_print("Error\nempty map name\n");
	if (checkmostatil(map) == -1)
		error_print("Error\nyour map must be rectangular\n");
	if (checkwalls2(map) == -1 || checkwalls(map) == -1)
		error_print("Error\nThe map must be closed/surrounded by walls\n");
	if (epc(map) == -1)
		error_print("Error\none if the elements is m,is missing !\n");
}
