/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:54 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/19 13:51:53 by ngennaro         ###   ########lyon.fr   */
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

char	**read_maps(char *file);
int		check_maps_validity(char **maps);
int		check_chr_validity(char **maps, t_gamerules *s_gamerules);
int		check_format(char **maps);
int		check_border(char **maps);
int		free_maps(char **maps);

#endif
