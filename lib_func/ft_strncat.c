/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:03:49 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/04 15:03:50 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	int		i;
	size_t	j;

	i = ft_strlen(dst);
	j = -1;
	while (src[++j] && j < len)
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst);
}
