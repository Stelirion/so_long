/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/06 11:52:37 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_mlx *mlx)
{
	(void)mlx;
	free_maps(mlx->maps);
	destroy_img(mlx);
	exit(0);
}

void	game(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->move = 0;
	create_windows(mlx);
	create_img(mlx);
	print_maps(mlx);
	mlx_key_hook(mlx->mlx_win, key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, (1L << 5), on_destroy, mlx);
	mlx_loop(mlx->mlx);
	destroy_img(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**maps;

	if (argc != 2)
		return (ft_printf("ERROR\ninvalid number of args"));
	if (check_extention(argv[1]) == 1)
		return (ft_printf("ERROR\nThe map need to be a .ber"));
	maps = read_maps(argv[1]);
	if (!maps)
		return (0);
	if (check_maps_validity(maps) == 1)
		return (free_maps(maps));
	mlx.maps = maps;
	locate_items(&mlx);
	game (&mlx);
}
