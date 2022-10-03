/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:11:57 by vly               #+#    #+#             */
/*   Updated: 2022/09/30 20:17:13 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	send_bits(char c, int pid)
{
	int	counter;

	counter = 7;
	while (counter >= 0)
	{
		if (c >> counter & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(25);
		counter--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		printf("Usage: ./client [pid] [message]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		printf("Invalid PID. Please try again.\n");
		return(0);
	}
	while (argv[2][i])
	{
		send_bits(argv[2][i++], pid);
	}
	return (1);
}