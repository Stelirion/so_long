/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:28:51 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/06 09:54:53 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_windows(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->maps[i])
		i++;
	while (mlx->maps[0][j])
		j++;
	mlx->mlx_win = mlx_new_window(mlx->mlx, 32 * j, 32 * i, "so_long");
}

void	create_img(t_mlx *mlx)
{
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx,
			"img/wall.xpm", &mlx->img_width, &mlx->img_height);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx,
			"img/floor.xpm", &mlx->img_width, &mlx->img_height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx,
			"img/player.xpm", &mlx->img_width, &mlx->img_height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx,
			"img/door.xpm", &mlx->img_width, &mlx->img_height);
	mlx->item = mlx_xpm_file_to_image(mlx->mlx,
			"img/chest.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->wall || !mlx->floor || !mlx->player || !mlx->item || !mlx->exit)
	{
		ft_printf("Error\nmissing texture");
		free_maps(mlx->maps);
		exit(0);
	}
}

void	destroy_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->floor);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->item);
	mlx_destroy_image(mlx->mlx, mlx->exit);
}

void	put_img(int i, int j, t_mlx *mlx, int type)
{
	if (type == '1')
		mlx_put_image_to_window(mlx->mlx,
			mlx->mlx_win, mlx->wall, 32 * j, 32 * i);
	else if (type == '0')
		mlx_put_image_to_window(mlx->mlx,
			mlx->mlx_win, mlx->floor, 32 * j, 32 * i);
	else if (type == 'P')
		mlx_put_image_to_window(mlx->mlx,
			mlx->mlx_win, mlx->player, 32 * j, 32 * i);
	else if (type == 'C')
		mlx_put_image_to_window(mlx->mlx,
			mlx->mlx_win, mlx->item, 32 * j, 32 * i);
	else if (type == 'E')
		mlx_put_image_to_window(mlx->mlx,
			mlx->mlx_win, mlx->exit, 32 * j, 32 * i);
}

void	print_maps(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->maps[i])
	{
		j = 0;
		while (mlx->maps[i][j])
		{
			put_img(i, j, mlx, mlx->maps[i][j]);
			j++;
		}
		i++;
	}
}
