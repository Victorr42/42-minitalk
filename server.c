/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:21:28 by vly               #+#    #+#             */
/*   Updated: 2022/09/26 20:31:57 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<string.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
#include "./libft/libft.h"
/*struct	sigaction
{
	void		(*sa_handler)(int);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(sa_sigaction)(int, siginfo_t*, void*);
	*/
	
void	myfunc(int signum, siginfo_t *siginfo, void *none)
{
	static int	c = 0;
	static int	bits = 0;
	static int	i;

	(void)none;
	c = c << 1;
	if (signum == SIGUSR1)
	{
		/*write(1, "1", 1);*/
		c = c + 1;
	}
	else if (signum == SIGUSR2)
	{
		/*write(1, "0", 1);*/
	}
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		bits = 0;
		c = 0;
		if (i != siginfo -> si_pid)
		{
			kill(siginfo -> si_pid, SIGUSR1);
			i = siginfo -> si_pid;
		}
	}
}

int	main()
{
	struct sigaction	act;

	act.sa_sigaction = myfunc;
	act.sa_flags = SA_SIGINFO;
	write(1, "Server PID is: ", 14);
	ft_putnbr_fd(getpid(),1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
