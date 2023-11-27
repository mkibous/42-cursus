/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/27 15:56:41 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    int i;
    static char *buf[OPEN_MAX];
    char *ret;
    int n;
    
    if (fd < 0  || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
        return (NULL);
    i = 0;
    buf[fd] = ft_readln(fd, buf[fd]);
    if(buf[fd] == NULL)
        return(NULL);
    if(buf[fd] == NULL)
        return(NULL);
    n = find_nl(buf[fd]);
    if (n == 0)
    {
        free(buf[fd]);
        buf[fd] = NULL;
        return ( NULL);
    }
    ret = ft_substr(buf[fd], 0, n, 0);
    if(buf[fd] + i)
        buf[fd] = ft_substr(buf[fd], n, ft_strlen(buf[fd]), 1);
    return (ret);
}
// #include <fcntl.h>
// int main ()
// {
//     char *line;
//     //char c = 0;
//     int fd = open("read.txt",O_RDONLY);
//     char c = 0;
//     int sd = open("rejf.txt", O_CREAT | O_RDWR, 0666);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     read(fd, &c, 1);
//     printf("%c", c);
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
// }
