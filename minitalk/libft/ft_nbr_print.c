/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:59:02 by vly               #+#    #+#             */
/*   Updated: 2022/06/24 19:59:05 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_nbr(size_t n)
{
	if (n > 9)
	{
		ft_put_nbr(n / 10);
		ft_put_nbr(n % 10);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

unsigned int	ft_nbr_print(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	ft_put_nbr(n);
	count += ft_nbr_count(n, 10);
	return (count);
}
