/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:38:06 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/10 15:20:10 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strclen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

int	check_file_extension(char *filename)
{
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nMap file extension has to be '.ber'.\n");
		return (-1);
	}
	return (0);
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if ((x < 0 || y < 0) || (x >= game->columns || y >= game->rows)
		|| (map[y][x] == 'F' || map[y][x] == '1'))
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == '0')
	{
		map[y][x] = 'F';
		if (map[y][x] == 'E')
			return ;
	}
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y - 1);
}
