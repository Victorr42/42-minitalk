/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:21:28 by vly               #+#    #+#             */
/*   Updated: 2022/09/29 22:08:54 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<string.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
#include "./libft/libft.h"

static void	handler(int sig_num)
{
	static int	bits;
	static char	c;

	if (sig_num == SIGUSR1)
	{
		c = (c << 1) | 0x01;
		bits++;
	}
	else if (sig_num == SIGUSR2)
	{
		c = 0x00;
		bits = 0;
	}
	if (bits == 8)
	{
		printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	
	pid = getpid();
		printf("Server PID is: %d\n", pid);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while(1)
		{
			sleep(1);
		}
	return (0);
}