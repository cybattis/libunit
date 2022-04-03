/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_logs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:08:58 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 16:24:03 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <fcntl.h>

void	log_test(t_unit_test *lst, t_test_data *t_data, char *f_name,
		int fd)
{
	t_data->test_count++;
	ft_putstr_fd(f_name, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(t_data->test_count, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(lst->test_name, fd);
	ft_putstr_fd(": ", fd);
}

void	log_test_status(int status, int fd)
{
	if (status == 0)
		ft_putstr_fd("\033[32m[OK]\n\033[0m", fd);
	else if (status == SIGSEGV)
		ft_putstr_fd("\033[33m[SIGSEGV]\n\033[0m", fd);
	else if (status == SIGBUS)
		ft_putstr_fd("\033[33m[SIGBUS]\n\033[0m", fd);
	else if (status == SIGABRT)
		ft_putstr_fd("\033[33m[SIGABRT]\n\033[0m", fd);
	else if (status == SIGFPE)
		ft_putstr_fd("\033[33m[SIGFPE]\n\033[0m", fd);
	else if (status == SIGPIPE)
		ft_putstr_fd("\033[33m[SIGPIPE]\n\033[0m", fd);
	else if (status == SIGILL)
		ft_putstr_fd("\033[33m[SIGILL]\n\033[0m", fd);
	else if (status == SIGALRM)
		ft_putstr_fd("\033[1;30m[TIMEOUT]\n\033[0m", fd);
	else
		ft_putstr_fd("\033[31m[KO]\n\033[0m", fd);
}

void	log_result(t_test_data test_data, int fd)
{
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(test_data.test_passed, fd);
	ft_putstr_fd("/", fd);
	ft_putnbr_fd(test_data.test_count, fd);
	ft_putstr_fd(" tests checked\t", fd);
	ft_putnbr_fd(test_data.test_failed_signal, fd);
	ft_putstr_fd(" tests failed by signal\n\n", fd);
}

int	create_log_file(void)
{
	int	fd;

	fd = open("log.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (!fd)
		return (-1);
	return (fd);
}
