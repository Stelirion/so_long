/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:54 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/05 17:20:03 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "./mlx/mlx.h"

typedef struct s_gamerules
{
	size_t	player;
	size_t	colectible;
	size_t	exit;
}	t_gamerules;

typedef struct s_mlx
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
	char	**maps;
}			t_mlx;

char	**read_maps(char *file);
int		check_maps_validity(char **maps);
int		check_chr_validity(char **maps, t_gamerules *s_gamerules);
int		check_format(char **maps);
int		check_border(char **maps);
int		free_maps(char **maps);
int		key_hook(int keycode, t_mlx *mlx);
void	create_windows(t_mlx *mlx);
void	print_maps(t_mlx *mlx);
void	create_img(t_mlx *mlx);
void	destroy_img(t_mlx *mlx);
void	put_img(int i, int j, t_mlx *mlx, int type);

#endif
