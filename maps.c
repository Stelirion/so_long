/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:52:48 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/06 08:38:21 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*delete_last_col(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		i++;
	line[i - 1] = '\0';
	return (line);
}

char	**read_maps(char *file)
{
	char	*line;
	char	**map;
	char	buffer[2];
	size_t	cursor;
	int		fd;

	cursor = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("ERROR\nThe file could not be opened"), NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (ft_printf("vA malloc fail"), NULL);
	line[0] = '\0';
	while (cursor != 0)
	{
		cursor = read(fd, buffer, 1);
		buffer[1] = '\0';
		line = ft_strjoin(line, (const char *)buffer);
	}
	line = delete_last_col(line);
	map = ft_split(line, '\n');
	if (!map)
		return (ft_printf("ERROR\nenter message about split"), NULL);
	return (free(line), map);
}

int	free_maps(char **maps)
{
	int	i;

	i = 0;
	while (maps[i])
	{
		free(maps[i]);
		i++;
	}
	free(maps);
	return (1);
}

void	locate_items(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->item_number = 0;
	while (mlx->maps[i])
	{
		j = 0;
		while (mlx->maps[i][j])
		{
			if (mlx->maps[i][j] == 'P')
			{
				mlx->player_x = j;
				mlx->player_y = i;
			}
			else if (mlx->maps[i][j] == 'C')
				mlx->item_number += 1;
			j++;
		}
		i++;
	}
	return ;
}

int	check_maps_validity(char **maps)
{
	t_gamerules	gamerules;

	gamerules.player = 0;
	gamerules.colectible = 0;
	gamerules.exit = 0;
	if (check_format(maps) == 1)
		return (ft_printf("ERROR\nthe map must be rectangular"), 1);
	if (check_chr_validity(maps, &gamerules) == 1)
		return (ft_printf("ERROR\ninvalid caractere"), 1);
	if (gamerules.player != 1)
		return (ft_printf("ERROR\ninvalid player count"), 1);
	if (gamerules.colectible < 1)
		return (ft_printf("ERROR\ninvalid colectible count"), 1);
	if (gamerules.exit != 1)
		return (ft_printf("ERROR\ninvalid exit count"), 1);
	if (check_border(maps) == 1)
		return (ft_printf("ERROR\nMissing border"), 1);
	return (0);
}
