/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:52:02 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/17 15:35:03 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len > 0)
	{
		while (src[i] != '\0' && i < len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	char			*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (i == start)
		{
			substr = copy(substr, &str[start], len);
		}
		i++;
	}
	return (substr);
}
