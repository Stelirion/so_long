/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 12:54:41 by ngennaro         ###   ########lyon.fr   */
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

void	print_maps(char **maps, t_mlx *mlx)
{
	int	i;
	int	j;

	mlx->mlx = mlx_init();
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, "img/wall.xpm", &mlx->img_width, &mlx->img_height);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx, "img/floor.xpm", &mlx->img_width, &mlx->img_height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "img/player.xpm", &mlx->img_width, &mlx->img_height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "img/door.xpm", &mlx->img_width, &mlx->img_height);
	mlx->item = mlx_xpm_file_to_image(mlx->mlx, "img/chest.xpm", &mlx->img_width, &mlx->img_height);
	i = 0;
	j = 0;
	while (maps[i])
		i++;
	while (maps[0][j])
		j++;
	mlx->mlx_win = mlx_new_window(mlx->mlx, 32 * j, 32 * i, "so_long");
	i = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall, 32 * j, 32 * i);
			else if (maps[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, 32 * j, 32 * i);
			else if (maps[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player, 32 * j, 32 * i);
			else if (maps[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->item, 32 * j, 32 * i);
			else if (maps[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit, 32 * j, 32 * i);
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->floor);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->item);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	char	**maps;
	t_mlx	mlx;

	if (argc != 2)
		return (ft_printf("ERROR, invalide number of args\n"));
	maps = read_maps(argv[1]);
	if (!maps)
		return (0);
	if (check_maps_validity(maps) == 1)
		return (free_maps(maps));
	text_maps(maps);
	print_maps(maps, &mlx);
}
