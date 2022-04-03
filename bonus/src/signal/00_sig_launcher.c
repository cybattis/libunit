/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_sig_launcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 17:03:40 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include "../../includes/sig_test.h"

int	signal_launcher(int fd)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "SIGABORT", &sigabort_test);
	load_test(&test_list, "SIGFPE", &sigfpe_test);
	load_test(&test_list, "SIGPIPE", &sigpipe_test);
	load_test(&test_list, "SIGILL", &sigill_test);
	launch_tests(test_list, "[SIGNAL]", fd);
	return (0);
}
