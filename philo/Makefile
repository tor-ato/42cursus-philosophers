# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:23:28 by tkitahar          #+#    #+#              #
#    Updated: 2025/01/03 14:02:04 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=philo

SRC_DIR:=src
OBJ_DIR:=obj

CFLAGS:=-Wall -Wextra -Werror -Iinclude -Isrc

SRC:= src/main.c \
		src/init/init.c \
		src/error/error.c \
		src/parse/parse.c \
		src/minilibft/ft_strlen.c \
		src/minilibft/ft_atol.c \
		src/minilibft/ft_isdigit.c \
		src/minilibft/ft_isspace.c \
		src/xlib/xmalloc.c \
		src/xlib/xmutex_handle.c \
		src/xlib/xthread_handle.c \


OBJ:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
