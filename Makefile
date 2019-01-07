# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 10:35:10 by tblaudez          #+#    #+#              #
#    Updated: 2018/07/26 21:35:37 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRC := ft_printf.c utils.c print_letters.c print_numbers.c utils2.c
override SRC := $(SRC:%=src/%)
LIB_FUNC := ft_atoi.c ft_bzero.c ft_charsrc.c ft_isdigit.c ft_islower.c ft_memcmp.c \
ft_memset.c ft_nbrdig.c ft_power.c ft_strcat.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strlen.c ft_strupcase.c ft_strreplace.c ft_strncat.c \
ft_strncpy.c ft_atoibase.c ft_tabset.c
override LIB_FUNC := $(LIB_FUNC:%=lib_func/%)
OBJ_DIR := objects/
OBJ := $(SRC:.c=.o) $(LIB_FUNC:.c=.o)
INCLUDES := includes/
FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@printf "\n\e[0;31mCréation du binaire - %s\e[0m\n" $(NAME)
	@ar rc $(NAME) $(OBJ) && \
	ranlib $(NAME)

%.o: %.c
	@printf "\e[0;32mCréation des .o - %-50s\e[0m\r" $@
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
