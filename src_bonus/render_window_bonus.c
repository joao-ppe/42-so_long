/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:18:37 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/20 17:59:36 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	render_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->columns * SIZE,
			(game->rows + 1) * SIZE, "so_long");
	if (game->win_ptr == NULL)
		return ;
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->columns * SIZE,
			(game->rows + 1) * SIZE);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp, 
			&game->img.line_len, &game->img.endian);
}

void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
		return ;
	render_map(game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &ft_quit,
		game);
	mlx_loop(game->mlx_ptr);
}
