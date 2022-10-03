/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:55:02 by vly               #+#    #+#             */
/*   Updated: 2022/06/24 19:55:12 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/* int	fd
 *
 * fd = open("filename", O_RWDR)
 * write(fd, "HELLO!", 6)     1 stdout, 0 stdin, 2 stderr
 * close(fd); */
