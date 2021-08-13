/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_client_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/08/13 08:18:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_client.h"

static void	ft_error(char *str)
{
	ft_putstr_fd("ERROR : \n", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}

static int	ft_send_char(int pid_server, const char char_to_send)
{
	int	i;
	int	j;

	signal(SIGUSR1, NULL);
	j = 1 << 6;
	while (j)
	{
		if (char_to_send & j)
			i = kill(pid_server, SIGUSR2);
		else
			i = kill(pid_server, SIGUSR1);
		if (i == -1)
			ft_error("server not found\n");
		j = j >> 1;
		usleep(100);
	}
	return (0);
}

static int	ft_sendstr(int pid_server, const char *str_to_send)
{
	while (*str_to_send)
	{
		if (ft_send_char(pid_server, *str_to_send) != 0)
			return (-1);
		str_to_send++;
	}
	if (ft_send_char(pid_server, *str_to_send) != 0)
		return (-1);
	return (0);
}

int	main(int argc, const char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error - incorrect arguments, ", 1);
		ft_putstr_fd("they must be at the form :\n", 1);
		ft_putstr_fd("./client [server PID] [string to send]\n", 1);
		return (-1);
	}
	return (ft_sendstr(ft_atoi(argv[1]), argv[2]));
}
