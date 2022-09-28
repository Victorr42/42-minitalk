/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:11:57 by vly               #+#    #+#             */
/*   Updated: 2022/09/26 20:20:11 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	send_bits(int pid, unsigned char c)
{
	int	counter;

	counter = 0;
	while (counter <= 7)
	{
		if (c & (0x80 >> counter))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter++;
		usleep(100);
	}
}

void	handler(int signum, siginfo_t *siginfo, void *none)
{
	(void)siginfo;
	(void)none;
	if (signum == SIGUSR1)
	{
		printf("message was receieved\n");
	}
}

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		printf("wrong number of arguments entered\n");
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
		send_bits(pid, argv[2][i++]);
	send_bits(pid, '\n');
	printf("\nMessage sent from:\n");
	return (0);
}
