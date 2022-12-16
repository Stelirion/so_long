/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:42:59 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/16 13:14:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*str_cpy;

	i = 0;
	len = ft_strlen(src);
	str_cpy = malloc(sizeof(char) * len + 1);
	if (str_cpy == NULL)
		return (0);
	while (src[i] != '\0' && i <= len)
	{
		str_cpy[i] = src[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
