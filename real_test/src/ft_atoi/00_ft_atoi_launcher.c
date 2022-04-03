/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_atoi_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 11:24:28 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_atoi_test.h"

int	ft_atoi_launcher(void)
{
	t_unit_test	*test_list = NULL;

	load_test(&test_list, "basic test", &ft_atoi_basic_test);
	load_test(&test_list, "minus sign test", &ft_atoi_minus_sign);
	load_test(&test_list, "plus sign test", &ft_atoi_plus_sign);
	load_test(&test_list, "multiple minus test", &ft_atoi_multi_minus_sign);
	launch_tests(test_list, "[FT_ATOI]");
	return (0);
}
