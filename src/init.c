/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:04:36 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/18 12:01:05 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->rows = 0;
	game->columns = 0;
	game->collectibles = 0;
	game->gathered = 0;
	game->collected = 0;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->coords.x = -1;
	game->coords.y = -1;
	game->tile.x = 0;
	game->tile.y = 0;
}

void	init_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	game->tile.y = SIZE;
	game->tile.x = SIZE;
}

t_game	*init(void)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	init_img(game);
	return (game);
}
