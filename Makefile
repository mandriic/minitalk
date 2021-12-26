# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandriic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 18:50:58 by mandriic          #+#    #+#              #
#    Updated: 2021/12/26 18:51:02 by mandriic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_SERV = 			./server.c\
					./minitalk_utils.c
SRC_CLIENT = 		./client.c\
					./minitalk_utils.c
SRC_SERV_BONUS = 	./server_bonus.c\
					./minitalk_utils_bonus.c
SRC_CLIENT_BONUS = 	./client_bonus.c\
					./minitalk_utils_bonus.c
OBJ_SERV = 	$(SRC_SERV:.c=.o)
OBJ_CLI = $(SRC_CLIENT:.c=.o)
OBJ_SERV_BONUS = $(SRC_SERV_BONUS:.c=.o)
OBJ_CLI_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
HEADER = 		./minitalk.h
HEADER_BONUS = 	./minitalk_bonus.h

all: $(NAME) $(NAME2) $(NAME_S_BONUS) $(NAME_C_BONUS)

bonus: $(NAME_S_BONUS) $(NAME_C_BONUS)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@


$(NAME): $(OBJ_SERV) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_SERV) -o $(NAME)

$(NAME2): $(OBJ_CLI) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_CLI) -o $(NAME2)

$(NAME_S_BONUS): $(OBJ_SERV_BONUS) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_SERV_BONUS) -o $(NAME_S_BONUS)

$(NAME_C_BONUS): $(OBJ_CLI_BONUS) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_CLI_BONUS) -o $(NAME_C_BONUS)

clean:
	rm -f $(OBJ_SERV) $(OBJ_CLI) $(OBJ_SERV_BONUS) $(OBJ_CLI_BONUS) 
fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_S_BONUS) $(NAME_C_BONUS)
re: fclean all
