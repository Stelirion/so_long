/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:51 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/16 13:39:23 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*copy_dest;
	const char	*copy_src;

	copy_dest = (char *)dest;
	copy_src = (char *)src;
	if (copy_dest <= copy_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			copy_dest[n - 1] = copy_src[n - 1];
			n--;
		}
	}
	return (dest);
}
