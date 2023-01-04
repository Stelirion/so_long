/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/04 15:23:22 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	text_maps(char **maps)
{
	int		i;

	i = 0;
	while (maps[i])
		ft_printf("%s\n", maps[i++]);
}

void	print_maps(char **maps)
{
	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;

	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*item;

	mlx = mlx_init();

	wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &img_width, &img_height);
	floor = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &img_width, &img_height);
	player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx, "img/door.xpm", &img_width, &img_height);
	item = mlx_xpm_file_to_image(mlx, "img/chest.xpm", &img_width, &img_height);

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps[i])
		i++;
	while (maps[0][j])
		j++;
	mlx_win = mlx_new_window(mlx, 32 * j, 32 * i, "so_long");

	i = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall, 32 * j, 32 * i);
			else if (maps[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, floor, 32 * j, 32 * i);
			else if (maps[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, player, 32 * j, 32 * i);
			else if (maps[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, item, 32 * j, 32 * i);
			else if (maps[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit, 32 * j, 32 * i);
			j++;
		}
		i++;
	}

	mlx_destroy_image(mlx, wall);
	mlx_destroy_image(mlx, floor);
	mlx_destroy_image(mlx, player);
	mlx_destroy_image(mlx, item);
	mlx_destroy_image(mlx, exit);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	char	**maps;

	if (argc != 2)
		return (ft_printf("ERROR, invalide number of args\n"));
	maps = read_maps(argv[1]);
	if (!maps)
		return (0);
	if (check_maps_validity(maps) == 1)
		return (free_maps(maps));
	text_maps(maps);
	print_maps(maps);
}
