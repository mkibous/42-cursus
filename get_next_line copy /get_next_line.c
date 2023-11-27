/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/27 15:52:47 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i;
    static char *buf;
    char *ret;
    char *rd;
    
    if (fd < 0  || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
        return (NULL);
    i = 0;
    rd = ft_readln(fd);
    if(buf == NULL && rd == NULL)
        return(NULL);
    if(rd == NULL && buf == NULL)
        return(NULL);
    if (buf == NULL)
        buf = strdup("");
    buf = ft_strjoin(buf, rd);
    if (buf == NULL)
        return(NULL);
    free(rd);
    if (find_nl(buf) == 0)
    {
        free(buf);
        buf = NULL;
        return ( NULL);
    }
    ret = ft_substr(buf, 0, find_nl(buf));
    if(buf + i)
        buf = ft_newbuf(buf);
    return (ret);
}
// #include <fcntl.h>
// int main ()
// {
//     char *line;
//     //char c = 0;
//     int fd = open("read.txt", O_CREAT | O_RDWR, 0666);
//     char c = 0;
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// }
