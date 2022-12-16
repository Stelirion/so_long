/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:44:31 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:15:19 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	var_type_str(char type, char *arg)
{
	size_t	i;

	i = 0;
	if (type == 's')
	{
		if (!arg)
		{
			write (1, "(null)", 6);
			return (6);
		}
		while (arg[i])
		{
			write (1, &arg[i], 1);
			i++;
		}
	}
	return (i);
}
