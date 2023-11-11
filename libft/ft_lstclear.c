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
    ds = NULL;
}
int main()
{
    t_list **lst;
    lst = (t_list **)malloc(sizeof(t_list *));
    char *str = "mehdi kibous";
    t_list *h = ft_lstnew(str);
    t_list *n = ft_lstnew(str);
    ft_lstadd_back(lst, h);
    ft_lstadd_back(lst, n);
    printf("this is the content : %s\n", (*lst)->content);
    printf("this is the content : %s\n", (*lst)->next->content);
    ft_lstclear(lst, ft_free);
    // printf("this is the content : %s\n", (*lst)->content);
    // (*lst) = (*lst)->next;
    //  printf("this is the content : %s\n", (*lst)->content);
    while(*lst)
    {
        printf("%s", (*lst)->content);
        *lst = (*lst)->next;
    }
    if(!*lst)
        printf("null");
    // printf("this is the content : %s\n", n->content);
    return 0;
}*/
