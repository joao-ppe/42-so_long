/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_movement_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:13:01 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/05 13:34:44 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_enemy(t_game *game)
{
	int	move;
	int	i;

	i = 0;
	while (i < game->enemy_n)
	{
		move = rand() % 4;
		if (move == 0 && move_enemy_up(game, i) == -1)
			continue ;
		else if (move == 1 && move_enemy_down(game, i) == -1)
			continue ;
		else if (move == 2 && move_enemy_left(game, i) == -1)
			continue ;
		else if (move == 3 && move_enemy_right(game, i) == -1)
			continue ;
		check_loss(game, i);
		i++;
	}
}

int	move_enemy_up(t_game *game, int i)
{
	t_point	pos;
	int		n_pos;

	pos.x = game->enemies[i].x;
	pos.y = game->enemies[i].y;
	n_pos = game->enemies[i].y - 1;
	if (validate_enemy_move(game, pos.x, n_pos) == 0)
	{
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/e_move_up.xpm", 
			pos.x * SIZE, n_pos * SIZE + ((SIZE / 3) * 2));
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/e_move_up.xpm", pos.x * SIZE, 
			n_pos * SIZE + ((SIZE / 3)));
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/enemy.xpm", pos.x * SIZE, n_pos * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		game->enemies[i].y = n_pos;
		game->map[pos.y][pos.x] = '0';
		game->map[n_pos][pos.x] = 'X';
		return (0);
	}
	return (-1);
}

int	move_enemy_down(t_game *game, int i)
{
	t_point	pos;
	int		n_pos;

	pos.x = game->enemies[i].x;
	pos.y = game->enemies[i].y;
	n_pos = game->enemies[i].y + 1;
	if (validate_enemy_move(game, pos.x, n_pos) == 0)
	{
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/e_move_down.xpm", 
			pos.x * SIZE, n_pos * SIZE - ((SIZE / 3) * 2));
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/e_move_down.xpm", pos.x * SIZE, 
			n_pos * SIZE - ((SIZE / 3)));
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/enemy.xpm", pos.x * SIZE, n_pos * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		game->enemies[i].y = n_pos;
		game->map[pos.y][pos.x] = '0';
		game->map[n_pos][pos.x] = 'X';
		return (0);
	}
	return (-1);
}

int	move_enemy_left(t_game *game, int i)
{
	t_point	pos;
	int		n_pos;

	pos.x = game->enemies[i].x;
	pos.y = game->enemies[i].y;
	n_pos = game->enemies[i].x - 1;
	if (validate_enemy_move(game, n_pos, pos.y) == 0)
	{
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/e_move_left.xpm", 
			n_pos * SIZE + ((SIZE / 3) * 2), pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/e_move_left.xpm",
			n_pos * SIZE + ((SIZE / 3)), pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/enemy.xpm", n_pos * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		game->enemies[i].x = n_pos;
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][n_pos] = 'X';
		return (0);
	}
	return (-1);
}

int	move_enemy_right(t_game *game, int i)
{
	t_point	pos;
	int		n_pos;

	pos.x = game->enemies[i].x;
	pos.y = game->enemies[i].y;
	n_pos = game->enemies[i].x + 1;
	if (validate_enemy_move(game, n_pos, pos.y) == 0)
	{
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/e_move_right.xpm", 
			n_pos * SIZE - ((SIZE / 3) * 2), pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/e_move_right.xpm", 
			n_pos * SIZE - ((SIZE / 3)), pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		usleep(30000);
		put_tile(game, "./assets/enemy.xpm", n_pos * SIZE, pos.y * SIZE);
		put_tile(game, "./assets/floor.xpm", pos.x * SIZE, pos.y * SIZE);
		game->enemies[i].x = n_pos;
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][n_pos] = 'X';
		return (0);
	}
	return (-1);
}
