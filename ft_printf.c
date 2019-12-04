/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:48:38 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/03 13:34:47 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printtwo(char *str, t_flags *flags, int n)
{
	char			*printstr;
	unsigned int	unint;

	if (*str == 'u')
	{
		getflag(flags, str - 1 - n);
		unint = va_arg(flags->valist, unsigned int);
		printstr = ft_strdup(ft_itoaun(unint));
		flagn(flags, printstr);
		if (flags->nprint == -1)
			return (0);
		ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

int		printthree(char *str, t_flags *flags, int n)
{
	char			*printstr;
	unsigned int	prinlong;

	if (*str == 'x' || *str == 'X')
	{
		getflag(flags, str - 1 - n);
		prinlong = va_arg(flags->valist, unsigned int);
		if (prinlong < 0)
			prinlong = UINT32_MAX - prinlong;
		printstr = ft_strdup(ft_itoahex(prinlong));
		if (*str == 'X')
			printstr = ft_strupcase(printstr);
		flagn(flags, printstr);
		if (flags->nprint == -1)
			return (0);
		ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

char	*printpls(t_flags *flags, char *str, int n)
{
	str++;
	flagszero(flags);
	n = getvar(str);
	str = str + n;
	flags->lenght += printone(str, flags, n);
	flags->lenght += printtwo(str, flags, n);
	flags->lenght += printthree(str, flags, n);
	flags->lenght += printfo(str, flags, n);
	flags->lenght += printfi(str, flags, n);
	flags->lenght += printsix(str, flags, n);
	flags->lenght += printlol(str, flags, n);
	if (*str == 's' || *str == 'c' || *str == 'p' || *str == 'd' || *str == 'i'
		|| *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		str++;
	if (flags->lspc != 0)
	{
		while (flags->lspc-- > 0)
		{
			ft_putchar_fd(32, 1);
			flags->lenght++;
		}
	}
	return (str);
}

int		printall(char *str, t_flags *flags)
{
	int	n;

	n = 0;
	flags->lenght = 0;
	while (*str)
	{
		if (*str == '%')
			str = printpls(flags, str, n);
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			flags->lenght++;
		}
	}
	va_end(flags->valist);
	return (flags->lenght);
}

int		ft_printf(const char *str, ...)
{
	int				result;
	t_flags			*flags;

	if (!str)
		return (0);
	if (!(flags = malloc(sizeof(*flags))))
		return (-1);
	va_start(flags->valist, str);
	flagszero(flags);
	result = printall((char *)str, flags);
	va_end(flags->valist);
	free(flags);
	return (result);
}
