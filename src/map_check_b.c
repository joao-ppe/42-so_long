/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:42:35 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/10 12:42:33 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_path(t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * game->rows);
	if (!map)
		return (0);
	while (++game->coords.y < game->rows)
		map[game->coords.y] = ft_strdup(game->map[game->coords.y]);
	flood_fill(map, game, game->player.x, game->player.y);
	game->coords.y = -1;
	while (++game->coords.y < game->rows)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->columns)
		{
			if (map[game->coords.y][game->coords.x] == 'C'
				|| map[game->coords.y][game->coords.x] == 'E')
			{
				ft_printf("Error\nNo valid path found.");
				free_array(map, game->rows);
				return (-1);
			}
		}
	}
	free_array(map, game->rows);
	return (0);
}

int	check_map_assets(t_game *game)
{
	t_point	coords;

	coords.y = -1;
	while (++coords.y < game->rows)
	{
		coords.x = -1;
		while (game->map[coords.y][++coords.x] != '\0')
		{
			if (game->map[coords.y][coords.x] != '0'
				&& game->map[coords.y][coords.x] != '1'
				&& game->map[coords.y][coords.x] != 'P'
				&& game->map[coords.y][coords.x] != 'E'
				&& game->map[coords.y][coords.x] != 'C'
				&& game->map[coords.y][coords.x] != '\n'
				&& game->map[coords.y][coords.x] != '\r')
			{
				ft_printf("Error\nInvalid character found.\n");
				return (-1);
			}
		}
	}
	return (0);
}

int	check_collectibles(t_game *game)
{
	if (game->collectibles <= 0)
	{
		ft_printf("Error\nNo collectibles found.\n");
		return (-1);
	}
	return (0);
}
