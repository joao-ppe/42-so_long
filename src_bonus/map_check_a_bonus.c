/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:27:23 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 14:47:00 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	count_map_assets(t_game *game)
{
	int	x;
	int	y;
	int	p_count;
	int	e_count;

	p_count = 0;
	e_count = 0;
	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map[y][x] == 'P')
				p_count++;
			else if (game->map[y][x] == 'E')
				e_count++;
		}
	}
	if (p_count != 1 || e_count != 1)
	{
		ft_printf("Error\nIncorrect number of players or exits.\n");
		return (-1);
	}
	return (0);
}

int	check_map_content(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collectibles++;
		}
	}
	return (count_map_assets(game));
}

int	check_map_size(t_game *game)
{
	int	y;

	y = -1;
	while (++y != game->rows)
	{
		if ((game->columns + game->rows <= 7) || (game->columns < 3
				|| game->rows < 3))
		{
			ft_printf("Error\nInvalid map size.\n");
			return (-1);
		}
		if ((ft_strclen(game->map[y]) != game->columns)
			&& (game->map[y] != NULL))
		{
			ft_printf("Error\nDifferent map rows size.\n");
			return (-1);
		}
	}
	return (0);
}

int	check_borders(t_game *game)
{
	t_point	coords;

	coords.y = -1;
	while (++coords.y < game->rows)
	{
		if (coords.y == 0 || coords.y == game->rows - 1)
		{
			coords.x = -1;
			while (++coords.x < game->columns)
			{
				if (game->map[coords.y][coords.x] != '1')
				{
					ft_printf("Error\nMissing wall.");
					return (-1);
				}
			}
		}
		else if (game->map[coords.y][0] != '1'
			|| game->map[coords.y][game->columns - 1] != '1')
		{
			ft_printf("Error\nMissing wall.");
			return (-1);
		}
	}
	return (0);
}

int	map_validation(t_game *game)
{
	if (check_map_size(game) == -1 || check_borders(game) == -1
		|| count_map_assets(game) == -1 || check_map_content(game) == -1
		|| check_map_assets(game) == -1 || check_valid_path(game) == -1
		|| check_collectibles(game) == -1)
		return (-1);
	return (0);
}
