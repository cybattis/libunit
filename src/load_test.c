/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/02 15:29:31 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **test_list, char *test_name, int (*f)(void))
{
	if (!test_list)
	{
		*test_list = ft_lstnew(test_name, f);
		if (!*test_list)
			return ;
	}
	else
		ft_lstadd_back(test_list, ft_lstnew(test_name, f));
}
