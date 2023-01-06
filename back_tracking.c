/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:33:53 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/06 16:27:07 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(char **maps)
{
	char	*temp;
	char	**temp_maps;
	int		i;

	temp = malloc(sizeof(char));
	temp[0] = '\0';
	i = 0;
	while (maps[i])
	{
		temp = ft_strjoin_free(temp, maps[i]);
		temp = ft_strjoin_free(temp, "\n");
		i++;
	}
	temp_maps = ft_split(temp, '\n');
	return (temp_maps);
}

int	check_faisability(t_mlx *mlx)
{
	char	**temp_maps;
	int		x;
	int		y;
	int		new;

	temp_maps = map_dup(mlx->maps);
	if (!temp_maps)
		return (1);
	new = 1;
	temp_maps[mlx->player_y][mlx->player_x] = '*';
	while (new != 0)
	{
		x = 0;
		new = 0;
		while (temp_maps[x])
		{
			y = 0;
			while (temp_maps[x][y])
			{
				if (temp_maps[x][y] == '*')
				{
					if (temp_maps[x + 1][y] == '0' ||
						temp_maps[x + 1][y] == 'C')
					{
						new = 1;
						temp_maps[x + 1][y] = '*';
					}
					if (temp_maps[x - 1][y] == '0' ||
						temp_maps[x - 1][y] == 'C')
					{
						new = 1;
						temp_maps[x - 1][y] = '*';
					}
					if (temp_maps[x][y + 1] == '0' ||
						temp_maps[x][y + 1] == 'C')
					{
						new = 1;
						temp_maps[x][y + 1] = '*';
					}
					if (temp_maps[x][y - 1] == '0' ||
						temp_maps[x][y - 1] == 'C')
					{
						new = 1;
						temp_maps[x][y - 1] = '*';
					}
				}
				y++;
			}
			x++;
		}
	}
	x = 0;
	while (temp_maps[x])
	{
		y = 0;
		while (temp_maps[x][y])
		{
			if (temp_maps[x][y] == 'C')
				return (1);
			if (temp_maps[x][y] == 'E')
			{
				if (temp_maps[x + 1][y] == '*')
					new = 1;
				else if (temp_maps[x - 1][y] == '*')
					new = 1;
				else if (temp_maps[x][y + 1] == '*')
					new = 1;
				else if (temp_maps[x][y - 1] == '*')
					new = 1;
				else
					return (free_maps(temp_maps), 1);

			}
			y++;
		}
		x++;
	}
	return (free_maps(temp_maps), 0);
}

