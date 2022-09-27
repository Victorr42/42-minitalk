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
#include <libft.a>

int	ft_atoi(char *s)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while ((s[a] >= 'a' && s[a] <= 'z') || (s[a] >= 'A' && s[a] <= 'Z'))
		a++;
	while ((s[a] >= '\t' && s[a] <= '\r') || s[a] == ' ')
		a++;
	if (s[a] == '-' || s[a] == '+')
	{
		if (s[a] == '-')
			b *= -1;
		a++;
	}
	while (s[a] >= '0' && s[a] <= '9')
	{
		c = (c * 10) + (s[a] - 48);
		a++;
	}	
	return (c * b);
}

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
		write(1, "\nserver: I got your message!\n", 29);
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
		write(1, "expect: ./client + pid + string\n", 32);
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
		send_bits(pid, argv[2][i++]);
	send_bits(pid, '\n');
	write(1, "\nMessage sent from:\n", 19);
	return (0);
}
