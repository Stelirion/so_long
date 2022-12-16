/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:08:56 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *src, int c, size_t size )
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	uns_c;

	i = 0;
	uns_c = (unsigned char)c;
	str = (unsigned char *)src;
	while (i < size)
	{
		if (str[i] == uns_c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
