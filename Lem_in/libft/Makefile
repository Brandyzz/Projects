# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 16:58:36 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/06 15:44:15 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
FLAGS = -Wall -Werror -Wextra
AR = ar rc
FILES = ft_islower.c ft_memmove.c ft_strcat.c ft_strjoin.c ft_strnstr.c \
		ft_isprint.c ft_memset.c ft_strchr.c ft_strlcat.c \
		ft_strrchr.c ft_isupper.c ft_putchar.c ft_strclr.c \
		ft_strlen.c ft_strstr.c ft_itoa.c ft_putchar_fd.c \
		ft_strcmp.c ft_strmap.c	ft_strsub.c ft_atoi.c \
		ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c \
		ft_strtrim.c ft_bzero.c	ft_memccpy.c ft_putendl_fd.c \
		ft_strdel.c ft_strncat.c ft_tolower.c ft_isalnum.c \
		ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c \
		ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
		ft_strequ.c ft_strncpy.c ft_isascii.c ft_memcpy.c \
		ft_putstr.c ft_striter.c ft_strnequ.c ft_isdigit.c \
		ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c \
		ft_strsplit.c ft_sqroot.c \
		ft_bitprint.c ft_bitsetfour.c ft_bitgetfour.c \
		ft_bitgetoctal.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_lstput.c ft_lstaddback.c \
		ft_lstremoveif.c ft_memdup.c ft_isdigit_str.c ft_strsplitdel.c \
		ft_split_whitespaces.c
		
NAME = libft.a
OBJ = $(FILES:.c=.o)
TEMP = Makefile~ libft.h~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
		@$(CC) $(FLAGS) -c $(FILES) && ar rc $(NAME) $(OBJ)

clean :
		@rm -f $(TEMP) $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all
