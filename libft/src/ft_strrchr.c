/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:33:00 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}
