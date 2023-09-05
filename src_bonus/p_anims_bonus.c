/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_anims_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:38:50 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:50:22 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	spawn_player_anim(t_game *game)
{
	int	p_pos;

	p_pos = game->player.y;
	loop_boost_anim(game, "./assets/instant_1.xpm", 
		"./assets/instant_2.xpm", 2);
	usleep(80000);
	put_tile(game, "./assets/instant_3.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_4.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_5.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/instant_6.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(120000);
	put_tile(game, "./assets/p_lvl0.xpm", game->player.x * SIZE, p_pos * SIZE);
	usleep(100000);
	lvl_up_anim_lvl1(game);
	put_tile(game, "./assets/p_lvl1.xpm", game->player.x * SIZE, p_pos * SIZE);
	usleep(80000);
}

void	pick_collectible_lvl1(t_game *game)
{
	int	p_pos;

	p_pos = game->player.y;
	put_tile(game, "./assets/pick_lvl1_1.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl1_2.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl1_3.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl1_4.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl1_5.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl1_6.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/p_lvl1.xpm", game->player.x * SIZE, p_pos * SIZE);
	usleep(80000);
}

void	pick_collectible_lvl2(t_game *game)
{
	int	p_pos;

	p_pos = game->player.y;
	put_tile(game, "./assets/pick_lvl2_1.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl2_2.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl2_3.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl2_4.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl2_5.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/pick_lvl2_6.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/p_lvl2.xpm", game->player.x * SIZE, p_pos * SIZE);
	usleep(80000);
}

void	lvl_up_anim_lvl1(t_game *game)
{
	int	p_pos;

	p_pos = game->player.y;
	put_tile(game, "./assets/lvl_up_1_1.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lvl_up_1_2.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lvl_up_1_3.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	loop_boost_anim(game, "./assets/lvl_up_1_4.xpm", 
		"./assets/lvl_up_1_5.xpm", 5);
	put_tile(game, "./assets/lvl_up_1_6.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(100000);
}

void	lvl_up_anim_lvl2(t_game *game)
{
	int	p_pos;

	p_pos = game->player.y;
	put_tile(game, "./assets/lvl_up_2_1.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lvl_up_2_2.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lvl_up_2_3.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	put_tile(game, "./assets/lvl_up_2_4.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(80000);
	loop_boost_anim(game, "./assets/lvl_up_2_5.xpm", 
		"./assets/lvl_up_2_6.xpm", 5);
	usleep(80000);
	put_tile(game, "./assets/p_lvl2.xpm", game->player.x * SIZE, 
		p_pos * SIZE);
	usleep(100000);
}
