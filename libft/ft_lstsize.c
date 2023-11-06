/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:28:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 18:06:41 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}
/*int main()
{
    char *str = "sgdgd";
    t_list *h = ft_lstnew(str);
    t_list *s =ft_lstnew(str);
    t_list *t = ft_lstnew(str);

    h->next = s;
    s->next = t;
    t->next = NULL;
    int size = ft_lstsize(h);
    printf("%d", size);
    free(h);
    free(s);
    free(t);

    return 0;
}*/