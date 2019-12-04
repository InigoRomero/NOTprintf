/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:06:10 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/04 11:25:06 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			flagszero(t_flags *flags)
{
	flags->lspc = 0;
	flags->rspace = 0;
	flags->nprint = 0;
	flags->nzero = 0;
	flags->leng = 0;
	flags->multi = 0;
	flags->nast = 0;
	flags->nast2 = 0;
}

char			*next(char *str, t_flags *flags)
{
	while (flags->leng-- > 0)
		str++;
	return (str);
}

int				getvar(char *str)
{
	int i;

	i = 0;
	while (*str == '-' || *str == '.' || *str == '*' || ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

static	void	helpme(t_flags *flags, char *str)
{
	if (flags->nzero > 0)
	{
		if (str[0] == '-')
			ft_putchar_fd('-', 1);
		if (str[0] == '0' && str[1] == 'x')
			ft_putstr_fd("0x", 1);
		while (flags->nzero-- > 0)
		{
			ft_putchar_fd('0', 1);
			flags->lenght++;
		}
		flags->nzero = 1;
	}
}

void			regulflags(t_flags *flags, char *str)
{
	if (flags->lspc > 0 && flags->nprint == -1)
		return ;
	else if (flags->lspc > 0 && flags->nprint > 0
			&& (size_t)flags->nprint < ft_strlen(str))
		flags->lspc = flags->lspc - flags->nprint;
	else if (flags->lspc > 0)
		flags->lspc = flags->lspc - ft_strlen(str);
	if (flags->nprint > 0 && flags->rspace > 0
			&& (size_t)flags->nprint < ft_strlen(str))
		flags->rspace = flags->rspace - flags->nprint;
	else if (flags->rspace > 0 && flags->nprint != -1)
		flags->rspace = flags->rspace - ft_strlen(str);
	if (flags->rspace > 0)
	{
		while (flags->rspace-- > 0)
		{
			ft_putchar_fd(32, 1);
			flags->lenght++;
		}
	}
	helpme(flags, str);
}
