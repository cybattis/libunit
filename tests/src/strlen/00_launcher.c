/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/02 16:51:05 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include "../../includes/ft_strlen_test.h"

int	strlen_launcher(void)
{
	t_unit_test	*test_list;

	load_test(&test_list, "Basic test", &basic_test);
	load_test(&test_list, "NULL test", &null_test);
	load_test(&test_list, "Timeout test", &timeout_test);
	launch_tests(test_list);
	return (0);
}
