/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:54:02 by vly               #+#    #+#             */
/*   Updated: 2022/06/24 19:54:25 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>*/
/*
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd (s[i], fd);
		i++;
	}
}

int	ft_num_count(size_t n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}
*/
int	ft_hex_print(unsigned long n, char c)
{
	int	count;

	count = ft_nbr_count(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ft_hex_print(n / 16, c);
		ft_hex_print(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n - 10 + 'a', 1);
		else
			ft_putchar_fd(n - 10 + 'A', 1);
	}
	return (count);
}
/*
int main(void)
{
	unsigned long	a;
	char	c;

	a = 180;
	c = 'x';
	ft_print_hex(a, c);
	return (0);
}
*/
