/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:02:55 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/04 15:02:57 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char			*s_dup;
	unsigned char	c_dup;

	c_dup = c;
	s_dup = s;
	while (n--)
		*s_dup++ = c_dup;
	return (s);
}
