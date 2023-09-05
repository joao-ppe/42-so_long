/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_anims_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:44:56 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/18 19:56:27 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	loop_boost_anim(t_game *game, char *anim_1, char *anim_2, int loops)
{
	int	i;
	int	p_pos;

	i = -1;
	p_pos = game->player.y;
	while (++i <= loops)
	{
		put_tile(game, anim_1, game->player.x * SIZE, p_pos * SIZE);
		usleep(90000);
		put_tile(game, anim_2, game->player.x * SIZE, p_pos * SIZE);
		usleep(90000);
	}
}
