/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:13:12 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/09/05 11:38:11 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *fileName)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(fileName, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open map file.\n");
		return (-1);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->rows)
		game->map[i] = get_next_line(fd);
}

void	read_map(char *file_name, t_game *game)
{
	int	fd;

	game->rows = count_lines(file_name);
	if (game->rows <= 0)
	{
		ft_printf("Error\nEmpty map.\n");
		ft_quit(game);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open map file.\n");
		return ;
	}
	game->map = malloc(sizeof(char *) * (game->rows));
	if (!game->map)
		return ;
	fill_map(fd, game);
	game->columns = ft_strclen(game->map[0]);
	close(fd);
}
