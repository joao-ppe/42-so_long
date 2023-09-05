/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movement_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:50:26 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:32:56 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_quit(game);
	else if (keysym == XK_w || keysym == XK_Up)
		validate_move_up(game);
	else if (keysym == XK_s || keysym == XK_Down)
		validate_move_down(game);
	else if (keysym == XK_a || keysym == XK_Left)
		validate_move_left(game);
	else if (keysym == XK_d || keysym == XK_Right)
		validate_move_right(game);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_moves(game);
	check_win(game);
	check_loss(game, -1);
	move_enemy(game);
	return (0);
}

void	validate_move_up(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y - 1][p_pos.x] == 'E' 
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y - 1][p_pos.x] == '1'))
		return ;
	else
	{
		if (game->level == 1)
			move_up_lvl1(game);
		else
			move_up_lvl2(game);
	}
}

void	validate_move_down(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y + 1][p_pos.x] == 'E' 
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y + 1][p_pos.x] == '1'))
		return ;
	else
	{
		if (game->level == 1)
			move_down_lvl1(game);
		else
			move_down_lvl2(game);
	}
}

void	validate_move_left(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y][p_pos.x - 1] == 'E' 
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y][p_pos.x - 1] == '1'))
		return ;
	else
	{
		if (game->level == 1)
			move_left_lvl1(game);
		else
			move_left_lvl2(game);
	}
}

void	validate_move_right(t_game *game)
{
	t_point	p_pos;

	p_pos = game->player;
	if ((game->map[p_pos.y][p_pos.x + 1] == 'E' 
		&& game->collected != game->collectibles)
		|| (game->map[p_pos.y][p_pos.x + 1] == '1'))
		return ;
	else
	{
		if (game->level == 1)
			move_right_lvl1(game);
		else
			move_right_lvl2(game);
	}
}
