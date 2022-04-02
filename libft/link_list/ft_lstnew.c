/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:39:43 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/10 11:55:49 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_unit_test	*ft_lstnew(char *test_name, int (*f)(void))
{
	t_unit_test	*new;

	new = (t_unit_test *)malloc(sizeof(t_unit_test) * 1);
	if (!new)
		return (NULL);
	new->test_name = ft_strdup(test_name);
	new->f = f;
	new->next = NULL;
	return (new);
}
