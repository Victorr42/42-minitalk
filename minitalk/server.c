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

/*static void	byte_handler(unsigned char c)
{
	if (c == 0)
	{
		printf("> Message sent successfully\n");
	}
	exit(0);
}*/

static void	handler(int sig_num)
{
	static int	bits;
	static int	c;

	if (sig_num == SIGUSR1)
		c += 1 << (7 - bits);
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
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
			pause();
		}
	return (0);
}