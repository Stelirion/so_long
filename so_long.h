/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:54 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/18 19:51:51 by ngennaro         ###   ########lyon.fr   */
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

char	**read_maps(char *file);
int	check_maps_validity(char **maps);

#endif
