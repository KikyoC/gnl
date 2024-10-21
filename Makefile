# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 19:37:58 by tom               #+#    #+#              #
#    Updated: 2024/10/21 15:02:25 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.out

SRCS = get_next_line_utils.c \
get_next_line.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
		$(CC) -o $@ -c $^ $(CFLAGS) -g

$(NAME): $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re