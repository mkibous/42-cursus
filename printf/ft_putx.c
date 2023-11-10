/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:29:39 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/08 21:31:37 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putx(unsigned int s, int *l)
{
	int		i;
	char	*hexa;
	char	ind[255];

	hexa = "0123456789abcdef";
	i = 0;
	while (s >= 16)
	{
		ind[i] = hexa[s % 16];
		s = s / 16;
		i++;
	}
	if (s < 16)
		ind[i] = hexa[s];
	while (i >= 0)
	{
		ft_putchar(ind[i], l);
		i--;
	}
}
