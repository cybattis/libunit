/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_atoi_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/02 18:37:21 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include "../../includes/ft_atoi_test.h"

int	ft_atoi_launcher(void)
{
	t_unit_test	*test_list = NULL;

	load_test(&test_list, "Basic test", &ft_atoi_basic_test);
	load_test(&test_list, "NULL test", &ft_atoi_null_test);
	load_test(&test_list, "Timeout test", &ft_atoi_timeout_test);
	launch_tests(test_list);
	return (0);
}
