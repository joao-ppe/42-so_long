/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_anims_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:18:37 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:37:49 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	enemy_spawn_anim(t_game *game)
{
	int	e;

	e = -1;
	while (++e < game->enemy_n)
	{
		loop_enemy_anim(game, "./assets/e_spawn_1.xpm",
			"./assets/e_spawn_2.xpm", e);
		usleep(50000);
		put_tile(game, "./assets/e_spawn_3.xpm",
			game->enemies[e].x * SIZE, game->enemies[e].y * SIZE);
		usleep(50000);
		put_tile(game, "./assets/enemy.xpm", game->enemies[e].x * SIZE, 
			game->enemies[e].y * SIZE);
	}
}

void	enemy_vanish_anim(t_game *game)
{
	int	e;

	e = game->enemy_n;
	while (--e != -1)
	{
		if (game->enemies[e].y > 0)
		{
			loop_enemy_anim(game, "./assets/e_vanish_1.xpm", 
				"./assets/e_vanish_2.xpm", e);
			usleep(25000);
			put_tile(game, "./assets/e_vanish_3.xpm", 
				game->enemies[e].x * SIZE, game->enemies[e].y * SIZE);
			usleep(25000);
			put_tile(game, "./assets/floor.xpm", game->enemies[e].x * SIZE, 
				game->enemies[e].y * SIZE);
		}
	}
}

void	loop_enemy_anim(t_game *game, char *anim_1, char *anim_2, int e)
{
	int	i;

	i = -1;
	while (++i <= 3)
	{
		put_tile(game, anim_1, game->enemies[e].x * SIZE, 
			game->enemies[e].y * SIZE);
		usleep(25000);
		put_tile(game, anim_2, game->enemies[e].x * SIZE, 
			game->enemies[e].y * SIZE);
		usleep(25000);
	}
}
