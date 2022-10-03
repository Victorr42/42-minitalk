/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:53:16 by vly               #+#    #+#             */
/*   Updated: 2022/06/24 19:53:31 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				ft_char_print(char c);
int				ft_hex_print(unsigned long n, char c);
int				ft_nbr_count(size_t n, int base);
unsigned int	ft_nbr_print(long n);
int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_specifier_check(const char c, va_list arg, int *i);
int				ft_str_print(char *str);
unsigned int	ft_strlen(const char *s);

#endif
