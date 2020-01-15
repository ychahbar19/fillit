# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 11:58:17 by ychahbar          #+#    #+#              #
#    Updated: 2019/02/27 11:00:35 by asouat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	check_reader.c \
		check_reader_tools.c \
		check_link_tetri.c \
		get_nxt_line.c \
		get_height_tetri.c \
		get_position_blocks.c \
		get_width_tetri.c \
		main.c \
		map_tools.c \
		print_map.c \
		solver.c \
		tetri_tools.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I libft/ -o $(NAME) $(SRCS) $(LIBFT)

all: $(NAME)

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY : all clean fclean re
