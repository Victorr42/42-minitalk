/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:55:51 by vly               #+#    #+#             */
/*   Updated: 2022/04/07 17:55:54 by vly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;

	len = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == 0)
		return (0);
	ft_memcpy(dst, s1, len);
	return (dst);
}
