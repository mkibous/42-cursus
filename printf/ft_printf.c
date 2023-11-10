/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:13:50 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/09 17:57:04 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_arg(va_list args, char c, int *l)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), l);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), l);
	else if (c == 'p')
		ft_hexad(va_arg(args, void *), l);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), l);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), l);
	else if (c == 'u')
		ft_putu(va_arg(args, unsigned int), l);
	else if (c == 'x')
		ft_putx(va_arg(args, int), l);
	else if (c == 'X')
		ft_putupx(va_arg(args, int), l);
	else if (c == '%')
		ft_putchar('%', l);
	else
	{
		ft_putchar('%', l);
		ft_putchar(c, l);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	args;

	va_start(args, str);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_arg(args, str[i], &l);
		}
		else
			ft_putchar(str[i], &l);
		i++;
	}
	va_end(args);
	return (l);
}
