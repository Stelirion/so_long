/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:56 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;
	size_t	n;
	size_t	j;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (ft_strlen(src) + size);
	n = size - dest_len - 1;
	j = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (dest_len + ft_strlen(src));
}
