# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/08/02 14:16:45 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minitalk
NAME_BONUS=minitalk_bonus
NAME_SERVER=minitalk_server
NAME_CLIENT=minitalk_client
SRCS_SERVER=$(addprefix ${FOLDER}/, \
	ft_minitalk_server_main.c)
SRCS_CLIENT=$(addprefix ${FOLDER}/, \
	ft_minitalk_client_main.c)
SRCS_SERVER_BONUS=$(addprefix ${FOLDER}/, \
	ft_minitalk_server_main_bonus.c)
OBJS_SERVER=$(SRCS_SERVER:.c=.o)
OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)
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

$(NAME_BONUS): $(SRCS_SERVER_BONUS) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

$(NAME_SERVER): $(OBJS_SERVER_BONUS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

$(NAME_CLIENT): $(OBJS_CLIENT)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a


%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

re_bonus: fclean bonus
