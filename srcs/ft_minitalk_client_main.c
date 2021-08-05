/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_client_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/08/05 17:39:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_client.h"

static int	ft_send_char(int pid_server, const char char_to_send)
{
	int	j;

	signal(SIGUSR1, NULL);
	j = 1 << 7; // 10000000
	while (j) //   10000000 -> 01000000 -> ... -> 00000001
	{
		if (char_to_send & j) // ?xxxxxxx & 10000000 -//-> xxxxxxx? & 000000001 
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		j = j >> 1;
		usleep(100);
	}
	//doesn't work  ? ... but it is something like that (check on server)
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
