# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/08/13 08:17:39 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minitalk
NAME_BONUS=minitalk_bonus
NAME_CLIENT=client
NAME_SERVER=server
NAME_SERVER_BONUS=server_bonus

SRCS_CLIENT=$(addprefix ${FOLDER}/, \
	ft_minitalk_client_main.c)
SRCS_SERVER=$(addprefix ${FOLDER}/, \
	ft_minitalk_server_main.c)
SRCS_SERVER_BONUS=$(addprefix ${FOLDER}/, \
	ft_minitalk_server_main_bonus.c)

OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)
OBJS_SERVER=$(SRCS_SERVER:.c=.o)
OBJS_SERVER_BONUS=$(SRCS_SERVER_BONUS:.c=.o)

INCLUDES=includes
FOLDER=srcs
LIBFT=$(addprefix ${INCLUDES}/, libft)

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT) bonus

$(NAME_BONUS): $(NAME_SERVER_BONUS) $(NAME_CLIENT)
	make -C $(LIBFT) bonus

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a


%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_SERVER_BONUS) $(NAME_CLIENT)

re: fclean all

re_bonus: fclean bonus
