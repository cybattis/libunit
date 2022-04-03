/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:03:45 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 18:39:05 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/includes/libunit.h"

void	ft_lstclear(t_unit_test **lst, void (*del)(void*))
{
	t_unit_test	*next;

	(void)del;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
//	*lst = NULL;
	free(lst);
}
