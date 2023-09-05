/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_anims_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:47:58 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:31:40 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	unlock_exit_anim(t_game *game)
{
	int	x;
	int	y;

	y = game->exit.y;
	x = game->exit.x;
	put_tile(game, "./assets/exit_floor_2.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_3.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_4.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_5.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_6.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_7.xpm", x * SIZE, y * SIZE);
	usleep(110000);
	put_tile(game, "./assets/exit_floor_8.xpm", x * SIZE, y * SIZE);
	usleep(11000);
	put_tile(game, "./assets/exit_floor_9.xpm", x * SIZE, y * SIZE);
	usleep(125000);
}

void	win_animation1(t_game *game)
{
	int	pos;

	pos = game->player.y;
	put_tile(game, "./assets/finish_1.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_2.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_3.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_4.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_5.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_6.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_7.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_8.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_9.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_10.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_11.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
}

void	win_animation2(t_game *game)
{
	int	pos;

	pos = game->player.y;
	put_tile(game, "./assets/finish_12.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(90000);
	put_tile(game, "./assets/finish_13.xpm", game->player.x * SIZE, pos * SIZE);
	put_tile(game, "./assets/finish_13.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(999999);
	put_tile(game, "./assets/instant_6.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_5.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_4.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_3.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_2.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_1.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/win_floor.xpm", game->player.x * SIZE, pos * SIZE);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(999999);
	usleep(250000);
}

void	death_animation1(t_game *game)
{
	int	pos;

	pos = game->player.y;
	put_tile(game, "./assets/death_1.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/death_2.xpm", game->player.x * SIZE, pos * SIZE);
	loop_boost_anim(game, "./assets/death_3.xpm", 
		"./assets/death_4.xpm", 5);
	usleep(80000);
	put_tile(game, "./assets/death_4.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/death_5.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(150000);
	loop_boost_anim(game, "./assets/death_6.xpm", 
		"./assets/death_7.xpm", 5);
	usleep(80000);
	put_tile(game, "./assets/death_8.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/death_9.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	death_animation2(game);
}

void	death_animation2(t_game *game)
{
	int	pos;

	pos = game->player.y;
	put_tile(game, "./assets/death_10.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/enemy.xpm", game->player.x * SIZE, pos * SIZE);
	loop_boost_anim(game, "./assets/e_vanish_1.xpm", 
		"./assets/e_vanish_2.xpm", 3);
	usleep(80000);
	put_tile(game, "./assets/e_vanish_3.xpm", 
		game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/e_vanish_4.xpm", 
		game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lose_floor.xpm",
		game->player.x * SIZE, pos * SIZE);
	enemy_vanish_anim(game);
	put_tile(game, "./assets/lose_floor.xpm",
		game->player.x * SIZE, pos * SIZE);
	usleep(999999);
	usleep(999999);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, pos * SIZE);
}
