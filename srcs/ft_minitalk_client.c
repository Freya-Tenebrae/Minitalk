/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/10 13:22:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_client.h"

static void	ft_error(char *str)
{
	ft_putstr_fd("\nERROR : ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(".\n", 1);
	ft_putstr_fd("The server didn't received the message correctly\n", 0);
	exit(EXIT_FAILURE);
}

static void	ft_send_char(int pid_server, const char char_to_send)
{
	int	i;
	int	j;

	j = 1 << 7;
	while (j)
	{
		if (char_to_send & j)
			i = kill(pid_server, SIGUSR2);
		else
			i = kill(pid_server, SIGUSR1);
		if (i == -1)
			ft_error("server can't be found");
		j = j >> 1;
		usleep(150);
	}
}

static void	ft_sendstr(int pid_server, const char *str_to_send)
{
	while (*str_to_send)
	{
		ft_send_char(pid_server, *str_to_send);
		str_to_send++;
	}
	ft_send_char(pid_server, *str_to_send);
}

int	main(int argc, const char **argv)
{
	if (argc != 3)
		ft_error("incorrect number of arguments");
	ft_sendstr(ft_atoi(argv[1]), argv[2]);
	ft_putstr_fd("The server received the message correctly\n", 0);
}
