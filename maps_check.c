/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:33:14 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/18 20:58:38 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chr_validity(char **maps, int *maps_rules)
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
				maps_rules[0] += 1;
			else if (maps[i][j] == 'C')
				maps_rules[1] += 1;
			else if (maps[i][j] == 'E')
				maps_rules[2] += 1;
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
