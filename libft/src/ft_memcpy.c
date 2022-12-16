/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:55:29 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < size)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
