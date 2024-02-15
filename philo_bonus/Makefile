# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 16:40:29 by ayman_marzo       #+#    #+#              #
#    Updated: 2024/02/15 14:43:57 by amarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = main.c parsing.c utils.c status.c semaphore.c

OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

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