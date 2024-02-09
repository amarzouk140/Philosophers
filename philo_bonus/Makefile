# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 11:01:48 by amarzouk          #+#    #+#              #
#    Updated: 2024/02/09 11:09:06 by amarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC =	action.c init_philo.c main_bonus.c parsing_bonus.c process.c time.c

CC = cc -pthread
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@ echo "philo_bonus compiled 🦧"

bonus: all

clean:
	@rm -rf philo_bonus

fclean:
	@rm -rf philo_bonus
	@echo "philo_bonus cleaned 🤘🏻"

re: fclean all

.PHONY : all bonus clean fclean re
