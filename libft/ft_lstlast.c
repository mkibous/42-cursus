/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:07:33 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 23:12:42 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if(lst)
    {
        while (lst->next)    
            lst = lst->next;
    }
    return (lst);
}

/*int main()
{
    char *str = "sgdgd";
    char *fg = "ahmed";
    t_list *h = ft_lstnew(str);
    t_list *s =ft_lstnew(str);
    t_list *t = ft_lstnew(fg);

    h->next = s;
    s->next = t;
    t->next = NULL;
    t_list *nnn  = ft_lstlast(t);
    printf("%s", nnn->content);
    free(h);
    free(s);
    free(t);
    return 0;
}*/