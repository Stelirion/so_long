/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:56 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/29 10:58:16 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort(char c, va_list args, int size)
{
	if (c == 'c' || c == 'i' || c == 'd')
		size += var_type_int(c, (int)va_arg(args, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		size += var_type_unsigned(c, (unsigned int)va_arg(args, unsigned int));
	else if (c == 's')
		size += var_type_str(c, (char *)va_arg(args, char *));
	else if (c == 'p')
		size += var_type_ptr(c, (unsigned long)va_arg(args, unsigned long));
	else
	{
		write (1, &c, 1);
		size++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	if (write(1, "", 0) != 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size = sort(str[i], args, size);
		}
		else
		{
			write (1, &str[i], 1);
			size ++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
