/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:29:49 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/14 15:09:14 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_tile(t_game *game, char *tile, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, tile,
			&game->tile.x, &game->tile.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.mlx_img, x, y);
}

void	render_corners(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		put_tile(game, "./assets/corner_top_left.xpm", x * SIZE, y * SIZE);
	else if (y == 0 && x == game->columns - 1)
		put_tile(game, "./assets/corner_top_right.xpm", x * SIZE, y * SIZE);
	else if (y == game->rows - 1 && x == 0)
		put_tile(game, "./assets/corner_bottom_left.xpm", x * SIZE, y * SIZE);
	else if (y == game->rows - 1 && x == game->columns - 1)
		put_tile(game, "./assets/corner_bottom_right.xpm", x * SIZE, y * SIZE);
}

void	render_borders(t_game *game, int x, int y)
{
	if (y == 0 && x > 0 && x < game->columns - 1)
		put_tile(game, "./assets/wall_top.xpm", x * SIZE, y * SIZE);
	else if (y > 0 && y < game->rows - 1 && x == 0)
		put_tile(game, "./assets/wall_left.xpm", x * SIZE, y * SIZE);
	else if (y > 0 && y < game->rows - 1 && x == game->columns - 1)
		put_tile(game, "./assets/wall_right.xpm", x * SIZE, y * SIZE);
	else if (y == game->rows - 1 && x > 0 && x < game->columns - 1)
		put_tile(game, "./assets/wall_bottom.xpm", x * SIZE, y * SIZE);
}

void	render_tiles(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1' && y > 0 && y < game->rows - 1
		&& x > 0 && x < game->columns - 1)
		put_tile(game, "./assets/block_floor.xpm", x * SIZE, y * SIZE);
	if (tile == '0')
		put_tile(game, "./assets/floor.xpm", x * SIZE, y * SIZE);
	else if (tile == 'P')
		put_tile(game, "./assets/floor.xpm", x * SIZE, y * SIZE);
	else if (tile == 'E')
		put_tile(game, "./assets/exit_floor_1.xpm", x * SIZE, y * SIZE);
	else if (tile == 'C')
		put_tile(game, "./assets/ball_floor.xpm", x * SIZE, y * SIZE);
}

void	render_map(t_game *game)
{
	game->coords.y = -1;
	while (++game->coords.y < game->rows)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->columns)
		{
			render_corners(game, game->coords.x, game->coords.y);
			render_borders(game, game->coords.x, game->coords.y);
			render_tiles(game, game->coords.x, game->coords.y);
			render_hud(game);
			render_moves(game);
		}
	}
	spawn_enemies(game);
	spawn_player_anim(game);
}
