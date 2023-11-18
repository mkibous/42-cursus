/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/18 20:42:08 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int j;
    static int i = 0;
    char *str;
    static char buf[BUFFER_SIZE];
    char *ret;
    
    if (fd < 0  || BUFFER_SIZE <= 0)
        return (NULL);
    j = 0;
    if(i == 0)
        read(fd, buf, BUFFER_SIZE);
    if(!buf[i])
        return (NULL);
    str = (buf + i);
    int l = ft_cont(str);
    if(l + i >= BUFFER_SIZE)
        l = BUFFER_SIZE - i;
    ret = (char *)malloc(l + 1);
    if (ret == NULL)
        return (NULL);
    while(j < l && buf[i] && buf[i] != '\n')
    {
        ret[j] = buf[i];
        i++;
        j++;
    }
    if(buf[i] == '\n')
    {
        ret[j] = buf[i];
        i++;
        j++;
    }
    ret[j] = '\0';
    return (ret);
}
// #include <fcntl.h>
// int main ()
// {
//     int fd = open("read_error.txt", O_CREAT);
    
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     // printf("%s\n", get_next_line(fd));
// }