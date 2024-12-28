# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:23:28 by tkitahar          #+#    #+#              #
#    Updated: 2024/12/28 21:54:12 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=philo

SRC_DIR:=src
OBJ_DIR:=obj

CFLAGS:=-Wall -Wextra -Werror -Iinclude -Isrc

SRC:=	\
		src/minilibft/ft_strlen.c \
		src/error/error.c \
		src/main.c

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
