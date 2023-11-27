/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:45:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/25 20:23:06 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
    if(c == NULL)
        return (0);
	while (c[i])
		i++;
	return (i);
}

int find_nl(char *s)
{
    int i = 0;
    
    while (s[i] && s[i] != '\n')
        i++;
    if(s[i] == '\n')
        i++;
    return(i);
}

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
	int	lt;
    int     j;
    int    i;
	char	*str;

	if (s2 == NULL || s1 == NULL)
		return (free(s1), NULL);
	i = 0;
    j = 0;
	lt = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(lt + 1);
    if(str == NULL)
        return(free(s1), NULL);
	while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
	while(s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
	return (free(s1), str);
}

char *ft_read(int fd)
{
    char *str;
    ssize_t z;
    
    str = (char *)malloc(BUFFER_SIZE + 1);
    if (str == NULL)
        return (NULL);
    z = read(fd, str, BUFFER_SIZE);
    if (z == -1)
        return (free(str), NULL);
    str[z] = '\0';
    return(str);
}

char *ft_readln(int fd)
{
    char *str;
    char *ret;
    // ssize_t z;
    
    str = ft_read(fd);
    if (str == NULL)
        return (NULL);
    ret = ft_strjoin(ft_strdup(""), str);
    while (find_nl(str) == BUFFER_SIZE && str[BUFFER_SIZE - 1] != '\n')
    {
        free(str);
        str = NULL;
        str = ft_read(fd);
        if (str == NULL)
            return (NULL);
        ret = ft_strjoin(ret, str);
    }
    free(str);
    return (ret);
}

char *ft_newbuf(char *str)
{
    int i;
    int j;
    int l;
    char *ret;
    
    i = 0;
    if(!str)
        return(NULL);
    j = find_nl(str);
    if(str[j] == '\0')
    {
        free(str);
        str = NULL;
        return(NULL);
    }
    l = ft_strlen(str + j);
    ret = (char *)malloc(l + 1);
    if (ret == NULL)
        return (free(str), NULL);
    while (i < l)
    {
        ret[i] = str [j];
        i++;
        j++;
    }
    ret[i] = '\0';
    free(str);
    return(ret);
}

char	*ft_substr(char *s, int start, int len)
{
	int	l;
	char	*str;
	int	i;

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
	return (str);
}
// #include <fcntl.h>
// int main ()
// {
//     char *line;
//     int fd = open("read.txt", O_CREAT | O_RDWR, 0666);
//        printf("%s", ft_read(fd));
//        printf("%s", ft_read(fd));
//        printf("%s", ft_read(fd));
//        printf("%s", ft_read(fd));
// }