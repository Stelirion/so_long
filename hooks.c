/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:47 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 17:21:54 by ngennaro         ###   ########lyon.fr   */
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

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		free_maps(mlx->maps);
		destroy_img(mlx);
		exit(0);
	}
	else if (keycode == 126)
		ft_printf("up\n", keycode);
	else if (keycode == 125)
		ft_printf("down\n", keycode);
	else if (keycode == 124)
		ft_printf("right\n", keycode);
	else if (keycode == 123)
		ft_printf("left\n", keycode);
	else
		return (0);
	text_maps(mlx->maps);
	ft_printf("key: %d\n--------------\n", keycode);
	return (0);
}
