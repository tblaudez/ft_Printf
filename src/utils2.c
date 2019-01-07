/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:19:44 by tblaudez          #+#    #+#             */
/*   Updated: 2018/07/08 16:20:33 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	putnbr_printf(intmax_t n, char (*cat)[CAT_BUF])
{
	if (n < 0)
	{
		(*cat)[CAT_BUF - 1] = '-';
		n *= -1;
	}
	itoabase_printf(n, 10, cat);
}

int		write_buffer(char (*string)[STR_BUF], t_printf *list, int *j, int x)
{
	if (ERROR)
		return (-1);
	ft_strreplace(*string, -1, '\0');
	write(1, string, (*j) + 1);
	if (x)
	{
		ft_bzero(string, STR_BUF);
		list->size += ((*j) + 1);
		*j = 0;
	}
	return (0);
}

void	put_bin(t_printf *list, va_list ap, char (*cat)[CAT_BUF])
{
	if (!((list->modif)[0]))
		itoabase_printf(va_arg(ap, unsigned int), 2, cat);
	else if (!ft_strcmp(list->modif, "h"))
		itoabase_printf((unsigned short)va_arg(ap, int), 2, cat);
	else if (!ft_strcmp(list->modif, "l"))
		itoabase_printf(va_arg(ap, unsigned long), 2, cat);
	else if (!ft_strcmp(list->modif, "hh"))
		itoabase_printf((unsigned char)va_arg(ap, int), 2, cat);
	else if (!ft_strcmp(list->modif, "ll"))
		itoabase_printf(va_arg(ap, unsigned long long), 2, cat);
	else if (!ft_strcmp(list->modif, "j"))
		itoabase_printf(va_arg(ap, uintmax_t), 2, cat);
	else if (!ft_strcmp(list->modif, "z"))
		itoabase_printf(va_arg(ap, size_t), 2, cat);
}

int		check_colors(char (*string)[STR_BUF], const char *restrict format)
{
	int			j;
	char		clr[10];
	const char	*colors[] = {"red", "green", "yellow",
	"magenta", "cyan", "eoc"};
	const char	*code[] = {"\x1B[31m", "\x1B[32m", "\x1B[33m",
	"\x1B[35m", "\x1B[36m", "\x1B[0m"};

	j = -1;
	ft_bzero(clr, 10);
	ft_strncpy(clr, format + 1, ft_charsrc((char*)format, '}') - 1);
	while (++j < 6)
		if (!(ft_strcmp((char *)clr, colors[j])))
		{
			ft_strcat(*string, code[j]);
			break ;
		}
	if (j >= 6)
		(*string)[ft_strlen(*string)] = '{';
	return (j < 6 ? ft_strlen(clr) + 1 : 0);
}
