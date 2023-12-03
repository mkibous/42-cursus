/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:36:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/02 20:43:29 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_find_nl(char *s);
int		ft_strlen(char *c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len, int f);
int		ft_strchr(char *str);
char	*ft_readln(int fd, char *buf);
#endif
