/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/18 13:56:37 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*temp;
	int		check;
	char	**maps;
	char	*buffer[2];
	int		fd;
	int		i;

	check = 1;
	i = 0;
	if (argc != 2)
		return (ft_printf("ERREUR, Nombre d'arguments invalide\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("ERREUR, Le fichier n'a pas pu etre ouvert\n"));
	temp = malloc(sizeof(char));
	if (!temp)
		return (ft_printf("ERREUR, Un malloc a echouer\n"));
	temp[0] = '\0';
	while (check != 0)
	{
		check = read(fd, buffer, 1);
		buffer[1] = "\0";
		temp = ft_strjoin_free(temp, (const char *)buffer);
	}
	maps = ft_split(temp, '\n');
	if (!maps)
		return (ft_printf("ERREUR, Le parsing de la map a echouer\n"));
	free(temp);
	while (maps[i])
		ft_printf("%s\n", maps[i++]);
}
