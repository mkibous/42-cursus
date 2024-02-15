/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:43:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/11/05 20:15:43 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
		new->next = *lst;
	if (new)
		*lst = new;
}

/*int main()
{
    char s1[] = "mehdi";
    char str[] = " kibous";

    t_list *s = ft_lstnew(str);
    t_list *n = ft_lstnew(s1);
    ft_lstadd_front(&s, n);
    while (s != NULL) {
        printf("%s", (char *)s->content);
        s = s->next;
    }
    while (s != NULL) {
        t_list *temp = s;
        free(temp->content);
        s = s->next;
        free(temp);
    }

    return 0;
}*/