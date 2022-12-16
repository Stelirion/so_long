/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../headers/ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:07:52 by ngennaro          #+#    #+#             */
/*   Updated: 2022/11/28 17:36:34 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	var_type_int(char type, int arg);
int	var_type_str(char type, char *arg);
int	var_type_unsigned(char type, unsigned int arg);
int	var_type_ptr(unsigned int type, unsigned long arg);

#endif
