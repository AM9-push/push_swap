# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachalla <aachalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:30:04 by aachalla          #+#    #+#              #
#    Updated: 2024/01/09 14:28:39 by aachalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c utils/src_lst.c utils/src_operation.c utils/src_lst_operation_2.c \
		utils/max_min_stack.c utils/max_min_stack_2.c utils/sort.c utils/last_touch.c \
		utils/cost.c utils/split.c utils/ft_atoi.c
SRC_bonus = checker.c utils_bonus/get_next_line.c utils_bonus/get_next_line_utils.c \
		utils_bonus/split.c utils_bonus/src_lst.c utils_bonus/src_operation.c \
		utils_bonus/src_lst_operation_2.c utils_bonus/check.c utils_bonus/sort.c \
		utils_bonus/ft_atoi.c

OBJ = $(SRC:.c=.o)
OBJ_bonus = $(SRC_bonus:.c=.o)

HEADER = utils/push_swap.h
HEADER_bonus = utils_bonus/checker.h

NAME = push_swap
NAME_bonus = checker

CC = cc
FLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

utils/%.o: utils/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(NAME_bonus)

$(NAME_bonus): $(OBJ_bonus)
	$(CC) $(FLAGS) $(OBJ_bonus) -o $(NAME_bonus)

utils_bonus/%.o: utils_bonus/%.c $(HEADER_bonus)
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ) $(OBJ_bonus)

fclean :clean
	$(RM) $(NAME) $(NAME_bonus)

re: fclean all

.PHONY: all bonus clean fclean re
