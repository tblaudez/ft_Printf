/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:16:58 by tblaudez          #+#    #+#             */
/*   Updated: 2018/09/04 10:59:26 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <limits.h>

# define STR_BUF 4096
# define CAT_BUF 2048

# define FLAGS (list->flags)
# define HASH (list->flags & (1 << 5))
# define ZERO (list->flags & (1 << 4))
# define MINUS (list->flags & (1 << 3))
# define PLUS (list->flags & (1 << 2))
# define SPACE (list->flags & (1 << 1))
# define ERROR (list->flags & 1)

typedef struct	s_printf
{
	char		flags;
	int			width;
	int			preci;
	char		modif[3];
	char		let;
	int			size;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
void			put_dec(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_hex(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_hex_cap(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_oct(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_unsigned(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_char(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_str(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_mem(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			put_bin(t_printf *list, va_list ap, char (*cat)[CAT_BUF]);
void			itoabase_printf(uintmax_t nbr, short base,
				char (*cat)[CAT_BUF]);
void			putnbr_printf(intmax_t n, char (*cat)[CAT_BUF]);
int				check_flags(char (*string)[STR_BUF],
				const char *restrict format, va_list ap, t_printf *list);
void			concat_string(char (*string)[STR_BUF], t_printf *list,
				va_list ap);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_charsrc(char *str, char c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_nbrdig(size_t n, int base);
uintmax_t		ft_power(int nbr, short pow);
char			*ft_strcat(char *dst, const char *src);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *s);
char			*ft_strupcase(char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			list_init(t_printf *list);
void			set_flags(t_printf *list, char c);
int				set_modifiers(t_printf *list, const char *restrict format);
void			ft_strreplace(char *str, int c, int x);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *dst, const char *src, size_t len);
int				ft_atoi_base(const char *str, int base);
int				*ft_tabset(int *tab, int c, int size);
int				write_buffer(char (*string)[STR_BUF], t_printf *list,
				int *j, int x);
int				check_colors(char (*string)[STR_BUF],
				const char *restrict format);

#endif
