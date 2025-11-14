# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 09:08:41 by jemonthi          #+#    #+#              #
#    Updated: 2025/11/14 11:21:00 by jemonthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

SOURCES	=	 ft_printf.c \
		 ft_printf_utils.c \
		 ft_printf_utils_second.c

OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rsc $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re
