/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:58:26 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	mul_overflow(size_t *dst, size_t a, size_t b)
{
	*dst = a * b;
	if (!a)
		return ((*dst) / b != a);
	return ((*dst) / a != b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	if (mul_overflow (&i, count, size))
		return (NULL);
	p = malloc(i);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, i);
	return (p);
}
