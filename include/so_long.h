/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:49:08 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/18 12:00:24 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		gathered;
	int		collected;
	int		moves;
	t_point	player;
	t_point	exit;
	t_point	coords;
	t_point	tile;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_game;

/*------------- Functions ---------------*/
// map_utils.c
int			count_lines(char *fileName);
void		fill_map(int fd, t_game *game);
void		read_map(char *file_name, t_game *game);
// init.c
void		init_game(t_game *game);
void		init_img(t_game *game);
t_game		*init(void);
// map_check_a.c & map_check_b.c
int			map_validation(t_game *game);
int			check_map_size(t_game *game);
int			check_borders(t_game *game);
int			check_map_content(t_game *game);
int			check_valid_path(t_game *game);
int			check_map_assets(t_game *game);
int			check_collectibles(t_game *game);
// map_check_utils.c
int			ft_strclen(const char *str);
int			check_file_extension(char *filename);
void		flood_fill(char **map, t_game *game, int x, int y);
// free_utils.c
void		free_map(char **map, t_game *game);
void		free_array(char **map, int lines);
void		free_all(t_game *game);
int			ft_quit(t_game *game);
// minilibx window render
void		render(t_game *game);
void		render_window(t_game *game);
int			handle_keypress(int keysym, t_game *game);
// render_map
void		render_map(t_game *game);
void		put_tile(t_game *game, char *tile, int x, int y);
void		render_corners(t_game *game, int y, int x);
void		render_borders(t_game *game, int y, int x);
void		render_tiles(t_game *game, int x, int y);
// movement
void		check_win(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
// movement_utils.c
int			handle_keypress(int keysym, t_game *game);
void		validate_move_up(t_game *game);
void		validate_move_down(t_game *game);
void		validate_move_left(t_game *game);
void		validate_move_right(t_game *game);

#endif
