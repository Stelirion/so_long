/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:33:14 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/09 15:04:23 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_maps_validity(char **maps)
{
	t_gamerules	gamerules;

	gamerules.player = 0;
	gamerules.colectible = 0;
	gamerules.exit = 0;
	if (check_format(maps) == 1)
		return (ft_printf("ERROR\nthe map must be rectangular\n"), 1);
	if (check_chr_validity(maps, &gamerules) == 1)
		return (ft_printf("ERROR\ninvalid chr\n"), 1);
	if (gamerules.player != 1)
		return (ft_printf("ERROR\ninvalid player count\n"), 1);
	if (gamerules.colectible < 1)
		return (ft_printf("ERROR\ninvalid colectible count\n"), 1);
	if (gamerules.exit != 1)
		return (ft_printf("ERROR\ninvalid exit count\n"), 1);
	if (check_border(maps) == 1)
		return (ft_printf("ERROR\nMissing border\n"), 1);
	return (0);
}

int	check_chr_validity(char **maps, t_gamerules *gamerules)
{
	int	i;
	int	j;

	i = 0;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == '1' || maps[i][j] == '0')
			{
			}
			else if (maps[i][j] == 'P')
				gamerules->player += 1;
			else if (maps[i][j] == 'C')
				gamerules->colectible += 1;
			else if (maps[i][j] == 'E')
				gamerules->exit += 1;
			else
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_format(char **maps)
{
	int	i;

	i = 0;
	while (maps[i])
	{
		if (i != 0)
		{
			if (ft_strlen(maps[i - 1]) != ft_strlen(maps[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_border(char **maps)
{
	int	i;
	int	x_max;
	int	y_max;

	i = 0;
	x_max = ft_strlen(maps[0]) - 1;
	while (maps[i])
	{
		if (maps[i][0] != '1' || maps[i][x_max] != '1')
			return (1);
		i++;
	}
	y_max = i - 1;
	i = 0;
	while (maps[0][i])
	{
		if (maps[0][i] != '1')
			return (1);
		if (maps[y_max][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] != 'r')
		return (1);
	i--;
	if (file[i] != 'e')
		return (1);
	i--;
	if (file[i] != 'b')
		return (1);
	i--;
	if (file[i] != '.')
		return (1);
	i--;
	if (i <= 0)
		return (1);
	return (0);
}
