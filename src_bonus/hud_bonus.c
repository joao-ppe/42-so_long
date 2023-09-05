/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:29:49 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 15:36:49 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	render_hud(t_game *game)
{
	int	i;

	i = 0;
	put_tile(game, "./assets/hud_ball.xpm", 0 * SIZE, game->rows * SIZE);
	while (++i < game->columns - 1)
		put_tile(game, "./assets/hud_bg.xpm", i * SIZE, game->rows * SIZE);
	put_tile(game, "./assets/hud_ball.xpm", (game->columns -1) * SIZE,
		game->rows * SIZE);
}

void	render_moves(t_game *game)
{
	char	*moves;
	int		x;
	int		y;

	moves = ft_itoa(game->moves);
	x = (game->columns / 2) * SIZE;
	y = game->rows * SIZE + 38;
	put_tile(game, "./assets/hud_bg.xpm", (game->columns / 2) * SIZE,
		game->rows * SIZE);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0x000000, "MOVES:");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0xCC0000, moves);
	free(moves);
}
