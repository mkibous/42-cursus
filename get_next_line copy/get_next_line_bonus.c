/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/02 20:31:19 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int	ft_find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*buf[OPEN_MAX];
	char		*ret;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	i = 0;
	buf[fd] = ft_readln(fd, buf[fd]);
	if (buf[fd] == NULL)
		return (NULL);
	if (buf[fd] == NULL)
		return (NULL);
	n = ft_find_nl(buf[fd]);
	if (n == 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	ret = ft_substr(buf[fd], 0, n, 0);
	if (buf[fd] + i)
		buf[fd] = ft_substr(buf[fd], n, ft_strlen(buf[fd]), 1);
	return (ret);
}
