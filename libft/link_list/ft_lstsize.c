/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:54:09 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/09 10:55:10 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	list = lst;
	while (list->next != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}
