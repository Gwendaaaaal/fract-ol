/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:47:24 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/20 11:51:48 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->above_value = 0;
	lst->below_value = 0;
	lst->rotate_to_top = 0;
	lst->rrotate_to_top = 0;
	lst->nb_op = 0;
	lst->next = NULL;
	return (lst);
}
