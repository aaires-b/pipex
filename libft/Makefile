# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 15:43:23 by anabelmonte       #+#    #+#              #
#    Updated: 2023/10/02 12:16:42 by aaires-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CFILES	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c	\
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BFILES = 	ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c \
			ft_lstsize.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c 
			
			
OFILES	= $(CFILES:.c=.o)
OFILESB = $(BFILES:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

${NAME} : ${OFILES}	

	ar rcs $(NAME) $(OFILES)

bonus: $(OFILES)	$(OFILESB)

	ar rcs $(NAME) $(OFILES) $(OFILESB)

clean:
	rm -f $(OFILES) $(OFILESB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
