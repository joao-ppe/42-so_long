/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:30:12 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/15 12:24:36 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_quit(t_game *game)
{
	free_all(game);
	exit (0);
}

void	free_array(char **map, int lines)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free(map);
		return ;
	}
	while (++i < lines)
		free (map[i]);
	free(map);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (++i < game->rows)
		free(game->map[i]);
	free(game->map);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}
