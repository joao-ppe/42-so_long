/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:49:08 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/22 18:11:46 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*------------- Includes ---------------*/
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
/*------------- Variables ---------------*/
# define SIZE 64
/*------------- Structures ---------------*/
typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		collected;
	int		moves;
	int		level;
	t_point	*enemies;
	int		enemy_n;
	t_point	player;
	t_point	exit;
	t_point	coords;
	t_point	tile;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_game;

/*------------- Functions ---------------*/
// Map utils
int			count_lines(char *fileName);
void		read_map(char *file_name, t_game *game);
// Inits
void		init_game(t_game *game);
void		init_img(t_game *game);
void		*init_enemies(t_game *game, int n);
t_game		*init(void);
// Game Check - Win & Loss
void		check_win(t_game *game);
void		check_loss(t_game *game, int e);
void		check_progress(t_game *game);
// Map verifications
int			map_validation(t_game *game);
int			check_map_size(t_game *game);
int			check_borders(t_game *game);
int			check_map_content(t_game *game);
int			check_valid_path(t_game *game);
int			check_map_assets(t_game *game);
int			check_collectibles(t_game *game);
// Map check utils
int			ft_strclen(const char *str);
int			check_file_extension(char *filename);
void		flood_fill(char **map, t_game *game, int x, int y);
// Free utils
void		free_map(char **map, t_game *game);
void		free_array(char **map, int lines);
void		free_all(t_game *game);
int			ft_quit(t_game *game);
// Minilibx Window Render
void		render(t_game *game);
void		render_window(t_game *game);
int			handle_keypress(int keysym, t_game *game);
// Map Render
void		render_map(t_game *game);
void		put_tile(t_game *game, char *tile, int x, int y);
void		render_corners(t_game *game, int y, int x);
void		render_borders(t_game *game, int y, int x);
void		render_tiles(t_game *game, int x, int y);
// Movement
void		move_up_lvl1(t_game *game);
void		move_up_lvl2(t_game *game);
void		move_down_lvl1(t_game *game);
void		move_down_lvl2(t_game *game);
void		move_left_lvl1(t_game *game);
void		move_left_lvl2(t_game *game);
void		move_right_lvl1(t_game *game);
void		move_right_lvl2(t_game *game);
// Movement Utils
int			handle_keypress(int keysym, t_game *game);
void		validate_move_up(t_game *game);
void		validate_move_down(t_game *game);
void		validate_move_left(t_game *game);
void		validate_move_right(t_game *game);
// Player animations
void		spawn_player_anim(t_game *game);
void		pick_collectible_lvl1(t_game *game);
void		pick_collectible_lvl2(t_game *game);
void		loop_boost_anim(t_game *game, char *anim_1,
				char *anim_2, int loops);
void		lvl_up_anim_lvl1(t_game *game);
void		lvl_up_anim_lvl2(t_game *game);
void		unlock_exit_anim(t_game *game);
// Enemy utils
int			validate_enemy_spawn(t_game *game, int x, int y);
int			count_zeros(t_game *game);
void		spawn_enemies(t_game *game);
// Enemy animations & movement
void		move_enemy(t_game *game);
int			validate_enemy_move(t_game *game, int x, int y);
int			move_enemy_up(t_game *game, int i);
int			move_enemy_down(t_game *game, int i);
int			move_enemy_left(t_game *game, int i);
int			move_enemy_right(t_game *game, int i);
void		enemy_spawn_anim(t_game *game);
void		loop_enemy_anim(t_game *game, char *anim_1, 
				char *anim_2, int e);
// Endgame animations
void		win_animation1(t_game *game);
void		win_animation2(t_game *game);
void		death_animation1(t_game *game);
void		death_animation2(t_game *game);
void		enemy_vanish_anim(t_game *game);
// HUD
void		render_hud(t_game *game);
void		render_moves(t_game *game);

#endif
