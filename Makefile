# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 13:25:41 by aaires-b          #+#    #+#              #
#    Updated: 2024/03/03 21:21:12 by aaires-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

SRCSFILES = parsing.c main.c

SRCSDIR = srcs/
OBJDIR = obj/
CC = cc 
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
## -g Includes debugging information in the executable
## -fsanitize=address : Enables AddressSanitizer, a memory error detector. It helps catch memory-related errors like buffer overflows
## bufferoverflow : are used to store and manipulate data, temporaryly. They have a fixed size allocated during program execution. 
## If a program attempts to write more data into a buffer than it can hold, the excess data can overflow into adjacent memory.
LIBFT = libft/libft.a
LIBFTDIR = libft
LIBFTFLAGS = -L ./libft/ -lft 
## to link external libraries 
## -L : used to specify the directory where the linker should look for library files
## -lft : -l flag is used to specify the name of the library to link. In this case, it's specifying the library name as "ft"
INCLUDE = -Iincludes -I/usr/include -Ilibft
#Specifies the directories to search for header files
#Include directories for header files.

SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))

OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all : $(NAME)
# : = dependencie

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) -o $(NAME)
## link the object files with the libraries.

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
# Represents the first prerequisite (dependency) in the rule.
# It holds the name of the file that the rule is supposed to build (target file). 
# -c : instructs the compiler to generate object files (*.o) without linking
#Specifies the output file or executable name.

$(LIBFT): 
	@make -C $(LIBFTDIR)
#prefix to suppress the echoing of the command being executed
#compiles the library
#changes where make is reading / executes the makefile of LIBFT.
#It allows you to run make from a different directory than where the Makefile is located

$(OBJDIR):
	mkdir -p $(OBJDIR)
#creates the directory
#The -p option ensures that it creates the parent directories if they don't exist.

clean : 
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re
#declare certain targets as "phony" or not representing actual files