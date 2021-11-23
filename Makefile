# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 08:53:37 by ael-oual          #+#    #+#              #
#    Updated: 2021/11/23 08:54:46 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = get_next_line.c get_next_line_utils.c  
BS = ft_lstnew_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = lib_fd.a
OBJ = $(SRC:.c=.o)
OBJB = $(BS:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
bonus: $(OBJB)
	ar -rc $(NAME) $(OBJB)
clean: 
	rm -f $(OBJ) $(OBJB)
fclean:clean
	rm -f $(NAME) 
re:fclean all bonus
