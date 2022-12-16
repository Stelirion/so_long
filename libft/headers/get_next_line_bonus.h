/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../headers/get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:50:21 by ngennaro          #+#    #+#             */
/*   Updated: 2022/12/14 14:38:47 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		is_end_line(const char *str, size_t *index);
char	*join(char const *s1, char const *s2);
void	buffer_clear(char *str, size_t len);

#endif
