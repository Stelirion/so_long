/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:44:31 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/28 13:14:00 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr(int nb, int i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (10);
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		i++;
	}
	if (nb >= 10 && nb != -2147483648)
	{
		i++;
		i = ft_putnbr(nb / 10, i);
	}
	ft_putchar(nb % 10 + '0');
	return (i);
}

int	var_type_int(char type, int arg)
{
	if (type == 'c')
	{
		ft_putchar(arg);
		return (1);
	}
	else if (type == 'i' || type == 'd')
	{
		return (ft_putnbr(arg, 0) + 1);
	}
	return (0);
}
