/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:42:36 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/16 13:39:53 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uns_s1;
	unsigned char	*uns_s2;

	i = 0;
	uns_s1 = (unsigned char *)s1;
	uns_s2 = (unsigned char *)s2;
	while ((uns_s1[i] || uns_s2[i]) && i < n)
	{
		if ((uns_s1[i] > uns_s2[i]) || (uns_s2[i] == '\0' && uns_s1[i] != '\0'))
			return (1);
		if ((uns_s1[i] < uns_s2[i]) || (uns_s1[i] == '\0' && uns_s2[i] != '\0'))
			return (-1);
		else
			i++;
	}
	return (0);
}
