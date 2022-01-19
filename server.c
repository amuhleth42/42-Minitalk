/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:19:38 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 18:21:30 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	handle_sigusr(int sigtype, siginfo_t *info, void *context)
{
	static int				c_pid;
	static int				i;
	static unsigned char	c;

	(void) context;
	if (c_pid == 0)
		c_pid = info->si_pid;
	c = c | (sigtype == SIGUSR1);
	i++;
	if (i != 8)
		c = c << 1;
	else
	{
		i = 0;
		if (c == 0)
		{
			kill(c_pid, SIGUSR1);
			c_pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
