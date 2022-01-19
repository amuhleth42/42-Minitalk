/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:18:26 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 18:19:33 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	handle_sigusr1(int sigtype)
{
	(void) sigtype;
	write(1, "Message received!\n", 18);
}

void	send_char(int s_pid, char c)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if ((c >> i) & 1)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(100);
	}
}

void	send_message(int s_pid, char *s)
{
	while (*s)
	{
		send_char(s_pid, *s);
		s++;
	}
	send_char(s_pid, '\0');
}

int	main(int argc, char **argv)
{
	int	s_pid;

	if (argc != 3)
	{
		ft_printf("Please enter the server's PID and a sentence to send\n");
		return (0);
	}
	signal(SIGUSR1, &handle_sigusr1);
	s_pid = ft_atoi(argv[1]);
	send_message(s_pid, argv[2]);
	return (0);
}
