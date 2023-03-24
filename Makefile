# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:35:01 by ataouaf           #+#    #+#              #
#    Updated: 2023/03/21 23:09:37 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ./src
OBJECTS = ./obj
INCLUDES = ./inc
NAME = so_long

SRCS = so_long.c utils.c write.c parse.c get_next_line_bonus.c get_next_line_utils_bonus.c image.c player.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.c=.o))

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(MLXFLAGS) $^ -o $@

${OBJECTS}/%.o : ${SOURCES}/%.c ${INCLUDES}/so_long.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re