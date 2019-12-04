/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:12:36 by iromero-          #+#    #+#             */
/*   Updated: 2019/12/03 12:45:39 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	getflag(t_flags *flags, char *str)
{
	int i;
	int count;

	count = 0;
	flags->leng = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				break ;
			count++;
			i = flagfive(flags, i, str);
		}
		i++;
		if (count >= 1)
			break ;
	}
}
