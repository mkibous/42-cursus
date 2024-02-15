/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:24:37 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 23:14:16 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *l;
    if(!lst || !new)
        return;
    l = ft_lstlast(*lst);
    if(*lst)
        l->next = new;
    else
        *lst = new;
}
/*int main()
{
    char *str = "sgdgd";
    char *fg = "ahmed";
    t_list *h = ft_lstnew(str);
    t_list *s =ft_lstnew(str);
    t_list *t = ft_lstnew(str);
    t_list *new = ft_lstnew(fg);

    h->next = s;
    s->next = t;
    t->next = NULL;
    ft_lstadd_back(&h, new);
    t_list *nnn  = ft_lstlast(h);
    printf("%s", nnn->content);
    free(h);
    free(s);
    free(t);
    free(new);
    return 0;
}*/