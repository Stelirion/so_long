/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:06:17 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:15:19 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	putptr(unsigned long number)
{
	long	i;
	long	size;
	char	*base;
	char	res[250];

	i = 0;
	base = "0123456789abcdef";
	write (1, "0x", 2);
	if (number == 0)
	{
		ft_putchar(base[0]);
		return (3);
	}
	while (number > 0)
	{
		res[i++] = base[number % 16];
		number /= 16;
	}
	size = i;
	i--;
	while (i >= 0)
		ft_putchar(res[i--]);
	return (size + 2);
}

int	var_type_ptr(unsigned int type, unsigned long arg)
{
	size_t	i;

	i = 0;
	if (type == 'p')
	{
		i = putptr(arg);
	}
	return (i);
}
