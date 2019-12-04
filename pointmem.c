/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:59:38 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/03 13:48:40 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int	get_digits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_itoamem(unsigned long n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = get_digits(numb);
	if (!(str = malloc((digits + 4) * sizeof(char))))
		return (NULL);
	str[digits--] = '\0';
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		if (numb % 16 <= 9)
			str[digits] = numb % 16 + '0';
		else if (numb % 16 < 16)
			str[digits] = numb % 16 + 'W';
		numb /= 16;
		digits--;
	}
	return (ft_strjoin("0x", str));
}

int			printsev(char *printstr, t_flags *flags, int i)
{
	if (flags->nzero > 0)
	{
		printstr = ft_substr(printstr, 2, ft_strlen(printstr));
		i += flags->nzero + 1;
	}
	if (flags->nprint == -1)
		return (0);
	ft_putstr_fd(printstr, 1);
	return (ft_strlen(printstr) + i);
}

int			printsix(char *str, t_flags *flags, int n)
{
	unsigned long	unlong;
	char			*printstr;
	int				i;

	if (*str == 'p')
	{
		i = 0;
		getflag(flags, str - 1 - n);
		unlong = va_arg(flags->valist, unsigned long);
		printstr = ft_strdup(ft_itoamem(unlong));
		if (flags->nprint > 0)
			flags->nprint += 2;
		if (flags->nprint == -1)
		{
			printstr = ft_strdup("0x");
			flags->nprint = 2;
		}
		flagn(flags, printstr);
		return (printsev(printstr, flags, i));
	}
	return (0);
}

int			printone(char *str, t_flags *flags, int n)
{
	if (*str == '%')
	{
		getflag(flags, str - 1 - n);
		if (flags->nzero > 0)
			flags->nzero--;
		regulflags(flags, "%");
		if (flags->nprint == -1)
			return (0);
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
