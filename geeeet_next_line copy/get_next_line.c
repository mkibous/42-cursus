/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/02 20:35:42 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buf;
	char		*ret;
	char		*rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	rd = ft_readln(fd);
	if (buf == NULL && rd == NULL)
		return (NULL);
	if (buf == NULL)
		buf = ft_strdup("");
	buf = ft_strjoin(buf, rd);
	if (buf == NULL)
		return (NULL);
	free(rd);
	if (ft_find_nl(buf) == 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	ret = ft_substr(buf, 0, ft_find_nl(buf), 0);
	if (buf + ft_find_nl(buf))
		buf = ft_substr(buf, ft_find_nl(buf), ft_strlen(buf), 1);
	return (ret);
}
