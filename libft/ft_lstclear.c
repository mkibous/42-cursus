/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:16:05 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 23:18:25 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *s;
    
    while(lst && *lst)
    {
        s = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = s;
    }
}
/*void ft_free(void *ds)
{
    free(ds);
}
int main()
{
    char str[] = "hello";
    t_list *h = ft_lstnew(str);
    h->content = malloc(10);
    ft_strlcpy(h->content, str, sizeof(str));
    t_list *n = ft_lstnew(str);
    n->content = malloc(10);
    ft_strlcpy(n->content, str, sizeof(str));
    h->next = n;
    n->next = NULL;
    printf("this is the content : %s\n", h->content);
    printf("this is the content : %s\n", n->content);
    ft_lstclear(&h, ft_free);
    if(h == NULL)
        printf("null");
    //printf("this is the content : %s\n", n->content);
    return 0;
}*/