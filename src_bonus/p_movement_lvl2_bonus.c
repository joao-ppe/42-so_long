/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movement_lvl2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:27:55 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/14 15:10:07 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_up_lvl2(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y - 1;
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./assets/m_up_lvl2.xpm",
		game->player.x * SIZE, n_pos * SIZE + ((SIZE / 3) * 2));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/m_up_lvl2.xpm", game->player.x * SIZE, n_pos * SIZE
		+ ((SIZE / 3)));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl2.xpm", game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
}

void	move_down_lvl2(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y + 1;
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./assets/m_down_lvl2.xpm",
		game->player.x * SIZE, n_pos * SIZE - ((SIZE / 3) * 2));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/m_down_lvl2.xpm", game->player.x * SIZE,
		n_pos * SIZE - ((SIZE / 3)));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl2.xpm", game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
}

void	move_left_lvl2(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x - 1;
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./assets/m_left_lvl2.xpm", n_pos * SIZE + ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/m_left_lvl2.xpm", n_pos * SIZE + ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl2.xpm", n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
}

void	move_right_lvl2(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x + 1;
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./assets/m_right_lvl2.xpm", n_pos * SIZE - ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/m_right_lvl2.xpm", n_pos * SIZE - ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl2.xpm", n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
}
