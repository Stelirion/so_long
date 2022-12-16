/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:44:31 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/28 13:28:10 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr(unsigned int nb, int i)
{
	if (nb >= 10)
	{
		i++;
		i = ft_putnbr(nb / 10, i);
	}
	ft_putchar(nb % 10 + '0');
	return (i);
}

static int	puthexa(unsigned int number, char type)
{
	long	i;
	long	size;
	char	*base;
	char	res[250];

	i = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (number == 0)
	{
		ft_putchar(base[0]);
		return (1);
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
	return (size);
}

int	var_type_unsigned(char type, unsigned int arg)
{
	if (type == 'u')
	{
		return (ft_putnbr(arg, 0) + 1);
	}
	else if (type == 'x' || type == 'X')
	{
		return (puthexa(arg, type));
	}
	return (0);
}
