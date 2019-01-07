/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:25:48 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/04 14:08:16 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	convert(char c, int base)
{
	int ret;

	if (c >= '0' && c <= '9')
		ret = c - 48;
	else if (c >= 'a' && c <= 'z')
		ret = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		ret = c - 65 + 10;
	else
		ret = -1;
	if (ret < base && ret != -1)
		return (ret);
	else
		return (-1);
}

static int	nbr_digits(const char *str, int base)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (convert(str[i], base) < 0)
			break ;
	}
	return (i);
}

int			ft_atoibase(const char *str, int base)
{
	int	ret;
	int	length;
	int	i;

	if (base == 10)
		return (ft_atoi(str));
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
	|| *str == '\r' || *str == ' ')
		str++;
	ret = 0;
	length = nbr_digits(str, base) - 1;
	i = -1;
	while (str[++i] && length >= 0 && convert(str[i], base) >= 0)
	{
		ret += convert(str[i], base) * ft_power(base, length);
		length--;
	}
	return (ret);
}
