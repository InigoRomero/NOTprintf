/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:12:31 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/04 12:13:00 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	flagone(t_flags *flags, int i, char *str)
{
	int aux;

	i++;
	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		flags->lspc = ft_atoi(ft_substr(str, i, aux));
		flags->leng += aux - i;
		i = i + (aux - i);
	}
	else
	{
		flags->lspc = va_arg(flags->valist, int);
		flags->leng += 2;
		i++;
	}
	if (flags->lspc < 0)
		flags->lspc *= -1;
	return (i);
}

static	int	flagtwo(t_flags *flags, int i, char *str)
{
	int aux;

	i++;
	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		flags->nprint = ft_atoi(ft_substr(str, i, aux));
		if (aux == i || flags->nprint == 0)
			flags->nprint = -1;
		flags->leng += aux - i + 1;
		i = i + (aux - i);
	}
	else
	{
		flags->nprint = va_arg(flags->valist, int);
		if (flags->nprint == 0)
		{
			flags->nast = -1;
			flags->nprint = -1;
		}
		flags->leng += 2;
	}
	return (i);
}

static	int	flagtre(t_flags *flags, int i, char *str, int aux)
{
	if (str[i + 1] != '-')
	{
		i++;
		if (str[i] != '*')
		{
			aux = i;
			while (ft_isdigit(str[aux]))
				aux++;
			flags->nzero = ft_atoi(ft_substr(str, i, aux));
			flags->leng += aux - i + 1;
			i = aux - 1;
		}
		else
		{
			flags->nzero = va_arg(flags->valist, int);
			flags->leng += 2;
		}
		if (flags->nzero < 0)
		{
			flags->lspc = flags->nzero * -1;
			flags->nzero = 0;
		}
	}
	return (i);
}

static	int	flagfour(t_flags *flags, int i, char *str)
{
	int aux;

	if (str[i] != '*')
	{
		aux = i;
		while (ft_isdigit(str[aux]))
			aux++;
		flags->rspace = ft_atoi(ft_substr(str, i, aux));
		flags->leng += aux - i + 1;
		i = i + (aux - i) - 1;
	}
	else
	{
		flags->rspace = va_arg(flags->valist, int);
		flags->leng += 2;
	}
	if (flags->rspace < 0)
	{
		flags->lspc = flags->rspace * -1;
		flags->rspace = 0;
	}
	return (i);
}

int			flagfive(t_flags *flags, int i, char *str)
{
	int aux;

	aux = 0;
	while (ft_isdigit(str[i]) || str[i] == '%'
			|| str[i] == '-' || str[i] == '.' || str[i] == '*')
	{
		i++;
		if (str[i] == '-')
			i = flagone(flags, i, str);
		if (str[i] == '.')
			i = flagtwo(flags, i, str);
		else if (str[i] == '0')
			i = flagtre(flags, i, str, aux);
		else if ((str[i] <= '9' && str[i] > '0') || str[i] == '*')
			i = flagfour(flags, i, str);
	}
	return (i);
}
