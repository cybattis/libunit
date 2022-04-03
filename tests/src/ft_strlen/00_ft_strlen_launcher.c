/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strlen_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 10:43:08 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include "../../includes/ft_strlen_test.h"

int	ft_strlen_launcher(void)
{
	t_unit_test	*test_list = NULL;

	load_test(&test_list, "Basic test", &ft_strlen_basic_test);
	load_test(&test_list, "NULL test", &ft_strlen_null_test);
	load_test(&test_list, "Timeout test", &ft_strlen_timeout_test);
	launch_tests(test_list, "ft_strlen");
	return (0);
}
