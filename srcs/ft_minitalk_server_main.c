/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/08/05 17:43:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_server.h"

static void	ft_byte_null()
{
	ft_putstr("byte = 0\n"); // something to do here and replace that
}

static void	ft_byte_one()
{
	ft_putstr("byte = 1\n"); // something to do here and replace that
}

static int	ft_loop()
{
	while (1)
	{
		pause();
		// something to do here
	}
	return (1);
}

int	main()
{
	struct sigaction	sa_bite_null;
	struct sigaction	sa_bite_one;

	sa_bite_null.sa_flags = SA_SIGINFO;
	sa_bite_one.sa_flags = SA_SIGINFO;
	sa_bite_null.sa_sigaction = ft_byte_null;
	sa_bite_one.sa_sigaction = ft_byte_one;
	sigaction(SIGUSR1, &sa_bite_null, NULL);
	sigaction(SIGUSR2, &sa_bite_one, NULL);
	ft_putstr("Server PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	return (ft_loop());
}

/*
write
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit
*/
