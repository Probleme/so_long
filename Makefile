# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:35:01 by ataouaf           #+#    #+#              #
#    Updated: 2023/04/15 16:24:43 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ./src
OBJECTS = ./obj
INCLUDES = ./inc
NAME = so_long
NAME_BONUS = so_long_bonus
SOURCES_BONUS = ./bonus
OBJECTS_BONUS = ./obj_bonus

SRCS = error.c so_long.c utils.c write.c wall.c get_next_line.c get_next_line_utils.c map.c draw.c mlx.c msg.c dfs.c
SRCS_BONUS = enemy.c error.c so_long.c utils.c write.c wall.c get_next_line.c get_next_line_utils.c map.c draw.c mlx.c msg.c dfs.c\
			ft_itoa.c move.c animation.c enemy_dir.c enemy_anim.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJECTS_BONUS)/, $(SRCS_BONUS:.c=.o))

RM = rm -rf

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

${OBJECTS}/%.o : ${SOURCES}/%.c ${INCLUDES}/so_long.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(MLXFLAGS) $^ -o $@

${OBJECTS_BONUS}/%.o : ${SOURCES_BONUS}/%.c ${INCLUDES}/so_long_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus