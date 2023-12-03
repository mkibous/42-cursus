/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:45:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/02 20:36:46 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		l;
	int		i;

	l = ft_strlen(s1);
	i = 0;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lt;
	int		j;
	int		i;
	char	*str;

	if (s2 == NULL || s1 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	lt = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(lt + 1);
	if (str == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_readln(int fd, char *buf)
{
	char	*str;
	ssize_t	z;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	z = 1;
	str[0] = '\0';
	if (!buf)
		buf = ft_strdup("");
	buf = ft_strjoin(buf, str);
	while (z > 0 && ft_strchr(str) == 0)
	{
		z = read(fd, str, BUFFER_SIZE);
		if (z == -1)
		{
			free(buf);
			return (free(str), NULL);
		}
		str[z] = '\0';
		buf = ft_strjoin(buf, str);
	}
	free(str);
	return (buf);
}

char	*ft_substr(char *s, int start, int len, int f)
{
	int		l;
	char	*str;
	int		i;

	l = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (l < len && s[start + l])
		l++;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	if (f == 1)
		free(s);
	return (str);
}
