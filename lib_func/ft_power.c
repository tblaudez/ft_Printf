/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:51:02 by tblaudez          #+#    #+#             */
/*   Updated: 2018/05/30 14:51:03 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_power(int nbr, short pow)
{
	size_t ret;

	ret = 1;
	if (pow < 0)
		return (0);
	while (pow--)
		ret *= nbr;
	return (ret);
}
