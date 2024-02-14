# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 16:40:29 by ayman_marzo       #+#    #+#              #
#    Updated: 2024/02/03 16:48:14 by ayman_marzo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = main.c parsing.c utils.c status.c 

OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 

all: $(NAME) clean

$(NAME): $(OBJ)
		 $(CC) $(CFLAGS) -o $(NAME) $(OBJ)
		 @echo Program $(NAME) is ready!! 🚀

clean:
		rm -rf $(OBJ)
		@echo Object files successfully deleted! 🧹

fclean: clean
		rm -f $(NAME)
		@echo Done!! 🎉

re: fclean all