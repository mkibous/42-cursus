/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:39:24 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/06 13:15:29 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new;
    t_list *first;

    first = NULL;
    //ft_lstadd_back(&lst, end);
    while (lst)
    {
        new = ft_lstnew(f(lst->content));
        if(!new)
        {
            ft_lstclear(&first, del);
            return (NULL);
        }
       ft_lstadd_back(&first, new);
        lst = lst->next;
    }
    return (first);
    
}
/*void *ft_f (void *s)
{
    return("mehdi");
}
void ft_free(void *ds)
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
    t_list *new = ft_lstmap(h, ft_f, ft_free);
    while (new)
    {
        printf("%s\n", new->content);
        new = new->next;
    }
    //printf("this is the content : %s\n", n->content);
    return 0;
}*/