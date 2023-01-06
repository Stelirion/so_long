/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:47 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/06 09:34:15 by ngennaro         ###   ########lyon.fr   */
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
	if (keycode == 53)
	{
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (keycode == 126)
		up (mlx);
	else if (keycode == 125)
		down (mlx);
	else if (keycode == 124)
		right (mlx);
	else if (keycode == 123)
		left (mlx);
	else
		return (0);
	print_maps(mlx);
	return (0);
}
