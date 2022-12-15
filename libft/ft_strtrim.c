/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:46:00 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/18 11:33:32 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;

	i = 0;
	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (to_trim(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (s1[i])
		i++;
	i--;
	while (to_trim(s1[i--], set))
		end ++;
	return (ft_substr(s1, start, (ft_strlen(s1) - start - end)));
}
