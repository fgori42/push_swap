# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgori <fgori@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 15:44:57 by fgori             #+#    #+#              #
#    Updated: 2024/03/12 14:10:07 by fgori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file = main.c\
		error.c\
		pa.c\
		rr.c\
		rrr.c\
		sa.c\
		sort_utilis.c\
		two_utlis.c\
		multi_move.c\
		check_goal.c\
		index.c\
		str.c\
		utilis.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./libft/lib

NAME = push_swap

all: $(NAME)

$(NAME): $(file)
	@$(MAKE) all -C libft
	@$(MAKE) bonus -C libft
	$(CC) $(CFLAGS) $(file) -L./libft -lft -o $(NAME)

clean:
	@$(MAKE) clean -C libft
fclean: clean
	rm -f $(NAME)
re: fclean all