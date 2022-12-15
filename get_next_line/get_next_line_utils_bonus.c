/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:27 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/14 14:35:02 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_end_line(const char *str, size_t *index)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	buffer_clear(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

char	*join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (free((void *)s1), NULL);
	str = malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (!str)
		return (free((void *)s1), NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free ((void *)s1);
	return (str);
}
