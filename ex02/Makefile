# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 17:41:48 by mstrauss          #+#    #+#              #
#    Updated: 2024/09/29 22:32:12 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fpnum

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++17 -stdlib=libc++
INC			=   -I$(CURDIR)

vpath %.hpp includes

SRC 		=	main.cpp\
				Fixed.cpp
				
HEADER		=	Fixed.hpp

OBJ_DIR		=	./obj
OBJ 		= 	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re