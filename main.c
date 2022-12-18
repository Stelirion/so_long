/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:24 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/18 16:06:38 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_maps(char **maps)
{
	int		i;

	i = 0;
	while (maps[i])
		ft_printf("%s\n", maps[i++]);
}

int	main(int argc, char **argv)
{
	char	**maps;

	if (argc != 2)
		return (ft_printf("ERREUR, Nombre d'arguments invalide\n"));
	maps = read_maps(argv[1]);
	if (!maps)
		return (ft_printf("ERREUR, Map invalide"));
	print_maps(maps);
}
