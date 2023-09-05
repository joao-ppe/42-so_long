/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:50:21 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/08/18 18:13:27 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	if (argc == 2 && check_file_extension(argv[1]) != -1)
	{
		game = init();
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error\nFailed to open map file.\n");
			return (ft_quit(game));
		}
		read_map(argv[1], game);
		if (map_validation(game) == -1)
			return (ft_quit(game));
		render(game);
		ft_quit(game);
	}
	return (0);
}
