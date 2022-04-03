/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:14:21 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 16:10:33 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	print_test(t_unit_test *lst, t_test_data *t_data, char *f_name)
{
	t_data->test_count++;
	ft_putstr_fd(f_name, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(t_data->test_count, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(lst->test_name, 1);
	ft_putstr_fd(": ", 1);
}

void	print_test_status(int status)
{
	if (status == 0)
		ft_putstr_fd("\033[32m[OK]\n\033[0m", 1);
	else if (status == SIGSEGV)
		ft_putstr_fd("\033[33m[SIGSEGV]\n\033[0m", 1);
	else if (status == SIGBUS)
		ft_putstr_fd("\033[33m[SIGBUS]\n\033[0m", 1);
	else if (status == SIGABRT)
		ft_putstr_fd("\033[33m[SIGABRT]\n\033[0m", 1);
	else if (status == SIGFPE)
		ft_putstr_fd("\033[33m[SIGFPE]\n\033[0m", 1);
	else if (status == SIGPIPE)
		ft_putstr_fd("\033[33m[SIGPIPE]\n\033[0m", 1);
	else if (status == SIGILL)
		ft_putstr_fd("\033[33m[SIGILL]\n\033[0m", 1);
	else if (status == SIGALRM)
		ft_putstr_fd("\033[1;30m[TIMEOUT]\n\033[0m", 1);
	else
		ft_putstr_fd("\033[31m[KO]\n\033[0m", 1);
}

void	print_result(int test_count, int test_passed)
{
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(test_passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(test_count, 1);
	ft_putstr_fd(" tests checked\n\n", 1);
}
