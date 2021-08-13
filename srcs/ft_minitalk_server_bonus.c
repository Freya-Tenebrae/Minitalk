/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/08/13 09:39:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_server.h"

static void	ft_error(char *str)
{
	ft_putstr_fd("ERROR : ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}

static void	ft_create_char_from_byte(int byte)
{
	static int				byte_number;
	static unsigned char	*c;

	if (c == NULL)
	{
		c = malloc(sizeof(char) * 1);
		if (c == NULL)
			ft_error("Malloc error.");
		*c = 0;
	}
	*c = (*c << 1) + byte;
	if (++byte_number > 7)
	{
		if (*c != '\0')
			ft_putchar(*c);
		else
			ft_putchar('\n');
		byte_number = 0;
		*c = 0;
	}
}

static void	ft_get_byte(int signal, struct __siginfo *info, void *cont)
{
	(void)info;
	(void)cont;
	if (signal == SIGUSR2)
		ft_create_char_from_byte(1);
	else if (signal == SIGUSR1)
		ft_create_char_from_byte(0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_get_byte;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (1);
}
