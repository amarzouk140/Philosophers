# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 14:22:27 by amarzouk          #+#    #+#              #
#    Updated: 2024/02/13 14:45:57 by amarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c init_data.c helper.c parsing.c observing.c threads.c routine.c

OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 

all: $(NAME) clean

$(NAME): $(OBJ)
		 @$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
		 @echo Program $(NAME) is ready!! 🚀

clean:
		rm -rf $(OBJ)
		@echo Object files successfully deleted! 🧹

fclean: clean
		rm -f $(NAME)
		@echo Done!! 🎉

re: fclean all
