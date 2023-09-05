/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:15 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/05 11:44:54 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_win(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		if (game->level == 1)
			pick_collectible_lvl1(game);
		else
			pick_collectible_lvl2(game);
		check_progress(game);
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected == game->collectibles)
	{
		win_animation1(game);
		win_animation2(game);
		usleep(999999);
		usleep(999999);
		ft_printf("You win!\n");
		ft_quit(game);
	}
	else
		return ;
}

void	check_loss(t_game *game, int e)
{
	if (e == -1)
	{
		while (++e < game->enemy_n)
		{
			if (game->player.x == game->enemies[e].x
				&& game->player.y == game->enemies[e].y)
			{
				game->enemies[e].y = 0;
				death_animation1(game);
				usleep(999999);
				ft_printf("You Lose!\n");
				ft_quit(game);
			}
		}
		return ;
	}
	else if (game->player.x == game->enemies[e].x
		&& game->player.y == game->enemies[e].y)
	{
		game->enemies[e].y = 0;
		death_animation1(game);
		usleep(999999);
		ft_printf("You Lose!\n");
		ft_quit(game);
	}
}

void	check_progress(t_game *game)
{
	int	i;

	i = 0;
	if (game->collectibles % 2 != 0)
		i = 1;
	if ((game->collected == (game->collectibles / 2) + i)
		&& game->level < 2)
	{
		game->level++;
		lvl_up_anim_lvl2(game);
	}
	if (game->collected == game->collectibles)
		unlock_exit_anim(game);
}
