/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:32:25 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/04 23:08:11 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cont(const char *s, char c)
{
	int	i;
	int	n;
	int	b;

	i = 0;
	b = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			b = 0;
		else if (b == 0)
		{
			n++;
			b = 1;
		}
		i++;
	}
	return (n);
}

int	ft_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	ft_cpy(char **str, const char *s, char c)
{
	size_t			l;
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		l = ft_len(s + i, c);
		str[j] = ft_substr(s, i, l);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	str[j] = (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_cont(s, c) + 1));
	if (str == NULL)
		return (NULL);
	ft_cpy(str, s, c);
	return (str);
}
