/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:19:21 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/03 13:49:22 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		longofnum(unsigned int n)
{
	int leng;

	leng = 0;
	while (n > 0)
	{
		n = n / 10;
		leng++;
	}
	return (leng);
}

static char		*inttochar(unsigned int n, char *num, int leng)
{
	num[leng--] = '\0';
	if (n == 0)
		num[0] = 48;
	while (n > 0)
	{
		num[leng--] = 48 + (n % 10);
		n = n / 10;
	}
	return (num);
}

char			*ft_itoaun(unsigned int n)
{
	char	*num;
	int		leng;

	leng = longofnum(n);
	if (!n)
		leng = 1;
	if (!(num = (char *)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	return (num = inttochar(n, num, leng));
}

int				printlol(char *str, t_flags *flags, int n)
{
	unsigned int unint;

	if (*str == 'c')
	{
		getflag(flags, str - 1 - n);
		unint = va_arg(flags->valist, int);
		regulflags(flags, "c");
		if (flags->nprint == -1)
			return (0);
		ft_putchar_fd((int)unint, 1);
		return (1);
	}
	return (0);
}
