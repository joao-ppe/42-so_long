/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_movement_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:13:09 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/05 11:15:43 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	validate_enemy_move(t_game *game, int x, int y)
{
	if ((x <= 0 || y <= 0)
		|| (x >= game->columns - 1 || y >= game->rows - 1))
		return (-1);
	if (game->map[y][x] == '1'
		|| game->map[y][x] == 'C'
		|| game->map[y][x] == 'E'
		|| game->map[y][x] == 'X')
		return (-1);
	return (0);
}
