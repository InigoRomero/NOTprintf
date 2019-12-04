/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:22:27 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/04 12:38:28 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		++i;
	}
	return (str);
}

void	flagnaux(t_flags *flags, char *printstr, int neg, int lng)
{
	if (flags->nzero > 0)
		flags->nzero -= lng;
	if (flags->nprint > lng)
	{
		flags->nzero += flags->nprint - lng + neg;
		flags->nprint = 0;
	}
	if (flags->nprint > 0)
		flags->nprint = 0;
	if (flags->lspc > 0 && flags->nzero > 0)
		flags->lspc -= flags->nzero;
	if (flags->rspace > 0 && flags->nzero > 0)
		flags->rspace -= flags->nzero;
	if (flags->nast == -1 && flags->rspace > 0)
		flags->rspace++;
	if (flags->nast == -1 && flags->lspc > 0)
		flags->lspc++;
	if (flags->nast == -1 && flags->nprint == -1)
		flags->nprint = 0;
	regulflags(flags, printstr);
}

void	flagn(t_flags *flags, char *printstr)
{
	int	neg;
	int	lng;

	lng = ft_strlen(printstr);
	neg = 0;
	if (printstr[0] == '-')
		neg = 1;
	if (flags->nzero > 0 && flags->nprint > 0)
	{
		flags->rspace = flags->nzero - flags->nprint;
		flags->nzero = flags->nzero - flags->rspace - lng + neg;
		if (flags->nzero < 0)
			flags->nzero = 0;
		flags->rspace += flags->nprint - flags->nzero;
		flags->nprint = 0;
		regulflags(flags, printstr);
		return ;
	}
	flagnaux(flags, printstr, neg, lng);
}

int		printfo(char *str, t_flags *flags, int n)
{
	char *printstr;

	if (*str == 's')
	{
		getflag(flags, str - 1 - n);
		printstr = va_arg(flags->valist, char*);
		if (!printstr)
			printstr = ft_strdup("(null)");
		if (flags->nzero > 0)
			flags->nzero -= ft_strlen(printstr);
		regulflags(flags, printstr);
		if (flags->nprint == -1)
			return (0);
		if ((ft_strlen(printstr) >= (size_t)flags->nprint
			&& flags->nprint != 0))
		{
			ft_putstr_fd(ft_substr(printstr, 0, flags->nprint), 1);
			return (flags->nprint);
		}
		else
			ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}

int		printfi(char *str, t_flags *flags, int n)
{
	char	*printstr;
	int		printint;

	if (*str == 'i' || *str == 'd')
	{
		getflag(flags, str - 1 - n);
		printint = va_arg(flags->valist, int);
		printstr = ft_strdup(ft_itoa(printint));
		flagn(flags, printstr);
		if (flags->nprint == -1)
			return (0);
		if (flags->nast == -1 && printint == 0)
			return (0);
		if (printstr[0] == '-' && flags->nzero == 1)
			ft_putstr_fd(printstr + 1, 1);
		else
			ft_putstr_fd(printstr, 1);
		return (ft_strlen(printstr));
	}
	return (0);
}
