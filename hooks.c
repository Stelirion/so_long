/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:47 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/09 12:44:37 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_mlx *mlx)
{
	if (mlx->maps[mlx->player_y - 1][mlx->player_x] ==
		'E' && mlx->item_number == 0)
	{
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		ft_printf("\n\n----------------\nCongratulation !!!\n");
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (mlx->maps[mlx->player_y - 1][mlx->player_x] == 'E')
		return (0);
	else if (mlx->maps[mlx->player_y - 1][mlx->player_x] != '1')
	{
		if (mlx->maps[mlx->player_y - 1][mlx->player_x] == 'C')
			mlx->item_number -= 1;
		mlx->maps[mlx->player_y][mlx->player_x] = '0';
		mlx->maps[mlx->player_y - 1][mlx->player_x] = 'P';
		mlx->player_y -= 1;
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		return (1);
	}
	return (0);
}

int	down(t_mlx *mlx)
{
	if (mlx->maps[mlx->player_y + 1][mlx->player_x] ==
		'E' && mlx->item_number == 0)
	{
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		ft_printf("\n\n----------------\nCongratulation !!!\n");
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (mlx->maps[mlx->player_y + 1][mlx->player_x] == 'E')
		return (0);
	else if (mlx->maps[mlx->player_y + 1][mlx->player_x] != '1')
	{
		if (mlx->maps[mlx->player_y + 1][mlx->player_x] == 'C')
			mlx->item_number -= 1;
		mlx->maps[mlx->player_y][mlx->player_x] = '0';
		mlx->maps[mlx->player_y + 1][mlx->player_x] = 'P';
		mlx->player_y += 1;
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		return (1);
	}
	return (0);
}

int	right(t_mlx *mlx)
{
	if (mlx->maps[mlx->player_y][mlx->player_x + 1] ==
		'E' && mlx->item_number == 0)
	{
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		ft_printf("\n\n----------------\nCongratulation !!!\n");
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (mlx->maps[mlx->player_y][mlx->player_x + 1] == 'E')
		return (0);
	else if (mlx->maps[mlx->player_y][mlx->player_x + 1] != '1')
	{
		if (mlx->maps[mlx->player_y][mlx->player_x + 1] == 'C')
			mlx->item_number -= 1;
		mlx->maps[mlx->player_y][mlx->player_x] = '0';
		mlx->maps[mlx->player_y][mlx->player_x + 1] = 'P';
		mlx->player_x += 1;
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		return (1);
	}
	return (0);
}

int	left(t_mlx *mlx)
{
	if (mlx->maps[mlx->player_y][mlx->player_x - 1] ==
		'E' && mlx->item_number == 0)
	{
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		ft_printf("\n\n----------------\nCongratulation !!!\n");
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (mlx->maps[mlx->player_y][mlx->player_x - 1] == 'E')
		return (0);
	else if (mlx->maps[mlx->player_y][mlx->player_x - 1] != '1')
	{
		if (mlx->maps[mlx->player_y][mlx->player_x - 1] == 'C')
			mlx->item_number -= 1;
		mlx->maps[mlx->player_y][mlx->player_x] = '0';
		mlx->maps[mlx->player_y][mlx->player_x - 1] = 'P';
		mlx->player_x -= 1;
		mlx->move += 1;
		ft_printf("moves : %i\n", mlx->move);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	char	*count;
	char	*count_itoa;

	if (keycode == 53)
	{
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (keycode == 13)
		up (mlx);
	else if (keycode == 1)
		down (mlx);
	else if (keycode == 2)
		right (mlx);
	else if (keycode == 0)
		left (mlx);
	else
		return (0);
	print_maps(mlx);
	count_itoa = ft_itoa(mlx->move);
	count = ft_strjoin("moves: ", count_itoa);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 5, 1042, count);
	return (free (count), free (count_itoa), 0);
}
