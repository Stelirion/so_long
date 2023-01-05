/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:28:51 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 13:38:06 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!mlx->mlx_win)
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