/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:49:42 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 21:40:46 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(!lst || !del)
        return;
    del(lst->content);
    free(lst);
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
    printf("this is the content : %s\n", h->content);
    ft_lstdelone(h, ft_free);
     printf("this is the content :%s", h->content);
    
    
    return 0;
}*/