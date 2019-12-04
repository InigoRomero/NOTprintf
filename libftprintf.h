/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:21:41 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/03 14:14:41 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags
{
	va_list	valist;
	int		lspc;
	int		rspace;
	int		nprint;
	int		nzero;
	int		leng;
	int		multi;
	int		nast;
	int		nast2;
	int		lenght;
}					t_flags;
char				*ft_itoaioctal(int n);
int					ft_printf(const char *str, ...);
char				*ft_itoaun(unsigned int n);
char				*ft_itoahex(long n);
char				*ft_itoamem(unsigned long n);
void				getflag(t_flags *flags, char *str);
void				flagszero(t_flags *flags);
char				*next(char *str, t_flags *flags);
int					getvar(char *str);
void				regulflags(t_flags *flags, char *str);
void				getastvar(const char *str, t_flags *flags);
char				*ft_strupcase(char *str);
void				flagn(t_flags *flags, char *printstr);
void				regulflagsn(t_flags *flags, char *str);
void				regulflagss(t_flags *flags, char *str);
int					flagfive(t_flags *flags, int i, char *str);
int					printfi(char *str, t_flags *flags, int n);
int					printfo(char *str, t_flags *flags, int n);
void				flagn(t_flags *flags, char *printstr);
void				flagnaux(t_flags *flags, char *printstr, int neg, int lng);
int					printsev(char *printstr, t_flags *flags, int i);
int					printsix(char *str, t_flags *flags, int n);
int					printone(char *str, t_flags *flags, int n);
int					printlol(char *str, t_flags *flags, int n);
int					printtwo(char *str, t_flags *flags, int n);
int					printthree(char *str, t_flags *flags, int n);
char				*printpls(t_flags *flags, char *str, int n);
int					printall(char *str, t_flags *flags);
#endif
