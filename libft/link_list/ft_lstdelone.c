/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:16:00 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/10 14:39:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ft_lstdelone(t_unit_test *test_list, void (*del)(void*))
{
	if (del)
		del(test_list->test_name);
	free(test_list);
}
