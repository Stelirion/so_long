# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:23:24 by ngennaro          #+#    #+#              #
#    Updated: 2022/12/16 12:04:23 by ngennaro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= src/ft_isalpha.c \
src/ft_isdigit.c \
src/ft_isalnum.c \
src/ft_isascii.c \
src/ft_isprint.c \
src/ft_strlen.c \
src/ft_memset.c \
src/ft_bzero.c \
src/ft_memcpy.c \
src/ft_memmove.c \
src/ft_strlcpy.c \
src/ft_strlcat.c \
src/ft_toupper.c \
src/ft_tolower.c \
src/ft_strchr.c \
src/ft_strrchr.c \
src/ft_strncmp.c \
src/ft_memchr.c \
src/ft_memcmp.c \
src/ft_strnstr.c \
src/ft_atoi.c \
src/ft_calloc.c \
src/ft_strdup.c \
src/ft_substr.c \
src/ft_strjoin.c \
src/ft_strtrim.c \
src/ft_putchar_fd.c \
src/ft_putstr_fd.c \
src/ft_putendl_fd.c \
src/ft_putnbr_fd.c \
src/ft_itoa.c \
src/ft_strmapi.c \
src/ft_split.c \
src/ft_striteri.c \
src/ft_printf.c \
src/var_type_int.c \
src/var_type_str.c \
src/var_type_unsigned.c \
src/var_type_ptr.c \
src/get_next_line_bonus.c \
src/get_next_line_utils_bonus.c


OBJS	= ${SRCS:.c=.o}

CC	= cc

HEADERS	= libft.h get_next_line_bonus.h ft_printf.h

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

all :		${NAME}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean
			$(MAKE) all

%.o: %.c	$(HEADERS) Makefile
			${CC} ${CFLAGS} -o $@ -c $< -I $(HEADERS)

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}

.PHONY:		all clean fclean re
