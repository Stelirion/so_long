/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 14:06:17 by ngennaro         ###   ########lyon.fr   */
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

int	main(int argc, char **argv)
{
	char	**maps;
	t_mlx	mlx;

	if (argc != 2)
		return (ft_printf("ERROR\ninvalid number of args"));
	maps = read_maps(argv[1]);
	if (!maps)
		return (0);
	if (check_maps_validity(maps) == 1)
		return (free_maps(maps));
	text_maps(maps);
	mlx.mlx = mlx_init();
	create_windows(maps, &mlx);
	create_img(&mlx);
	print_maps(maps, &mlx);
	mlx_loop(mlx.mlx);
	destroy_img(&mlx);
}
