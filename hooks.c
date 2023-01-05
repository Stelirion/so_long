/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:47 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 17:54:06 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	text_maps(char **maps)
{
	int		i;

	i = 0;
	while (maps[i])
		ft_printf("%s\n", maps[i++]);
}

int	up (t_mlx *mlx)
{
	(void) mlx;
	ft_printf("\n--------------\nup\n");
	return (1);
}

int	down (t_mlx *mlx)
{
	(void) mlx;
	ft_printf("\n--------------\ndown\n");
	return (1);
}

int	right (t_mlx *mlx)
{
	(void) mlx;
	ft_printf("\n--------------\nright\n");
	return (1);
}

int	left (t_mlx *mlx)
{
	(void) mlx;
	ft_printf("\n--------------\nleft\n");
	return (1);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	static size_t move;

	if (!move)
		move = 0;
	if (keycode == 53)
	{
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (keycode == 126)
		move += up (mlx);
	else if (keycode == 125)
		move += down (mlx);
	else if (keycode == 124)
		move += right (mlx);
	else if (keycode == 123)
		move += left (mlx);
	else
		return (0);
	text_maps(mlx->maps);
	ft_printf("move : %i", move);
	return (0);
}
