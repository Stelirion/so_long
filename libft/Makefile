# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:23:24 by ngennaro          #+#    #+#              #
#    Updated: 2022/12/18 13:23:37 by ngennaro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_itoa.c \
ft_strmapi.c \
ft_split.c \
ft_striteri.c \
ft_printf.c \
var_type_int.c \
var_type_str.c \
var_type_unsigned.c \
var_type_ptr.c \
get_next_line_bonus.c \
get_next_line_utils_bonus.c \
ft_strjoin_free.c

DIR_SRCS = src/

DIR_OBJS = .objs/

DIR_HEAD = headers/

OBJS	=	${SRCS:%.c=${DIR_OBJS}%.o}

CC	= cc

MKDIR	=	mkdir -p

HEADERS	= 	libft.h \
			get_next_line_bonus.h \
			ft_printf.h

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

all :		${NAME}

clean :
			rm -rf ${DIR_OBJS}

fclean :	clean
			rm -rf ${NAME}

re :		fclean
			$(MAKE) all

${DIR_OBJS}%.o: 	${DIR_SRCS}%.c	${addprefix ${DIR_HEAD}, ${HEADERS}} Makefile | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}

.PHONY:		all clean fclean re
