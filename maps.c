/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:52:48 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/04 15:20:28 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_maps(char *file)
{
	char	*temp;
	int		check;
	char	**maps;
	char	buffer[2];
	int		fd;

	check = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("ERROR, The file could not be opened\n"), NULL);
	temp = malloc(sizeof(char));
	if (!temp)
		return (ft_printf("ERROR, A malloc fail\n"), NULL);
	temp[0] = '\0';
	while (check != 0)
	{
		check = read(fd, buffer, 1);
		buffer[1] = '\0';
		temp = ft_strjoin_free(temp, (const char *)buffer);
	}
	maps = ft_split(temp, '\n');
	if (!maps)
		return (ft_printf("ERROR, Map parsing failed\n"), NULL);
	return (free(temp), maps);
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

int	check_maps_validity(char **maps)
{
	t_gamerules	gamerules;

	gamerules.player = 0;
	gamerules.colectible = 0;
	gamerules.exit = 0;
	if (check_format(maps) == 1)
		return (ft_printf("Error, the map must be rectangular"), 1);
	if (check_chr_validity(maps, &gamerules) == 1)
		return (ft_printf("Error, invalid caractere"), 1);
	if (gamerules.player != 1)
		return (ft_printf("Error, invalid player count"), 1);
	if (gamerules.colectible < 1)
		return (ft_printf("Error, invalid colectible count"), 1);
	if (gamerules.exit != 1)
		return (ft_printf("Error, invalid exit count"), 1);
	if (check_border(maps) == 1)
		return (ft_printf("Error, Missing border"), 1);
	return (0);
}
