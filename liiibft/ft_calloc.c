/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:39:57 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/01 19:29:13 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	void	*s;

	totalsize = count * size;
	s = (malloc(totalsize));
	if (s == NULL)
		return (NULL);
	ft_bzero(s, totalsize);
	return (s);
}
