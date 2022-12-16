/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:17:54 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/22 13:04:45 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	long int	long_n;
	int			len;

	len = 1;
	long_n = (long int)n;
	if (long_n < 0)
	{
		len++;
		long_n *= -1;
	}
	while (long_n > 9)
	{
		long_n /= 10;
		len++;
	}
	return (len);
}

static void	strrev(char *tab)
{
	size_t	i;
	size_t	b;
	char	c;

	i = 0;
	b = ft_strlen(tab) - 1;
	while (i < ft_strlen(tab) / 2)
	{
		c = tab[i];
		tab[i] = tab[b];
		tab[b] = c;
		i = i + 1;
		b = b - 1;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	long_n;
	int			i;

	str = malloc (sizeof(char) * (size(n) + 1));
	if (!str)
		return (NULL);
	i = 0;
	long_n = (long int)n;
	if (long_n < 0)
		long_n *= -1;
	while (long_n > 9)
	{
		str[i] = long_n % 10 + '0';
		long_n /= 10;
		i++;
	}
	str[i++] = long_n % 10 + '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	strrev(str);
	return (str);
}
