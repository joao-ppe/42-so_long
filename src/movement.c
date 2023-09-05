/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:27:55 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/05 15:06:17 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_win(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected != game->collectibles)
	{
		return ;
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected == game->collectibles)
	{
		ft_printf("You win!\n");
		ft_quit(game);
	}
}

void	move_up(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y - 1;
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./assets/p_lvl0.xpm", 
		game->player.x * SIZE, n_pos * SIZE + ((SIZE / 3) * 2));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", game->player.x * SIZE, n_pos * SIZE
		+ ((SIZE / 3)));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_win(game);
}

void	move_down(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y + 1;
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./assets/p_lvl0.xpm", 
		game->player.x * SIZE, n_pos * SIZE - ((SIZE / 3) * 2));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", game->player.x * SIZE, n_pos * SIZE
		- ((SIZE / 3)));
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./assets/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_win(game);
}

void	move_left(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x - 1;
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE + ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE + ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_win(game);
}

void	move_right(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x + 1;
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE - ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE - ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./assets/p_lvl0.xpm", n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./assets/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_win(game);
}
