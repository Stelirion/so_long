/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:52:48 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/18 20:38:32 by ngennaro         ###   ########lyon.fr   */
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
		return (ft_printf("ERREUR, Le fichier n'a pas pu etre ouvert\n"), NULL);
	temp = malloc(sizeof(char));
	if (!temp)
		return (ft_printf("ERREUR, Un malloc a echouer\n"), NULL);
	temp[0] = '\0';
	while (check != 0)
	{
		check = read(fd, buffer, 1);
		buffer[1] = '\0';
		temp = ft_strjoin_free(temp, (const char *)buffer);
	}
	maps = ft_split(temp, '\n');
	if (!maps)
		return (ft_printf("ERREUR, Le parsing de la map a echouer\n"), NULL);
	return (free(temp), maps);
}

int	check_maps_validity(char **maps)
{
	int	maps_rules[3];

	maps_rules[0] = 0;
	maps_rules[1] = 0;
	maps_rules[2] = 0;
	if (check_format(maps) == 1)
		return (ft_printf("Error, Map non rectangulaire"), 1);
	if (check_chr_validity(maps, maps_rules) == 1)
		return (ft_printf("Error, Caractere invalide"), 1);
	if (maps_rules[0] != 1)
		return (ft_printf("Error, nombre de joueur invalide"), 1);
	if (maps_rules[1] < 1)
		return (ft_printf("Error, nombre de colectibles invalide"), 1);
	if (maps_rules[2] != 1)
		return (ft_printf("Error, nombre de sorties invalide"), 1);
	if (check_border(maps) == 1)
		return (ft_printf("Error, Map non cloturer"), 1);
	return (0);
}
