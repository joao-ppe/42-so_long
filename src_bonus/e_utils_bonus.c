/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_movement_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:13:09 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:13:34 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include <time.h>

void	spawn_enemies(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	srand(time(NULL));
	game->enemy_n = count_zeros(game) / 20;
	game->enemies = init_enemies(game, game->enemy_n);
	while (++i < game->enemy_n)
	{
		x = 0;
		y = 0;
		while (validate_enemy_spawn(game, x, y) != 0)
		{
			x = rand() % game->columns;
			y = rand() % game->rows;
		}
		game->enemies[i].x = x;
		game->enemies[i].y = y;
		game->map[y][x] = 'X';
	}
	enemy_spawn_anim(game);
}

int	validate_enemy_spawn(t_game *game, int x, int y)
{
	if ((x <= 0 || y <= 0)
		|| (x >= game->columns || y >= game->rows))
		return (-1);
	if (game->map[y][x] == 'C' || game->map[y][x] == '1'
		|| game->map[y][x] == 'E' || game->map[y][x] == 'P')
		return (-1);
	return (0);
}

int	count_zeros(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i <= game->rows - 1)
	{
		j = -1;
		while (++j <= game->columns - 1)
		{
			if (game->map[i][j] == '0')
				count++;
		}
	}
	return (count);
}
