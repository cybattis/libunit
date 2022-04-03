/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:52:29 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 18:09:46 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static pid_t	fork_test(t_unit_test *testlist)
{
	pid_t	pid;
	int		fd;
	int		return_value;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		fd = open("tmp.txt", O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
			exit(-1);
		dup2(fd, 1);
		dup2(fd, 2);
		if (TIMEOUT > 0)
			alarm(TIMEOUT);
		return_value = testlist->f();
		ft_lstclear(&testlist, NULL);
		close(fd);
		exit(return_value);
	}
	return (pid);
}

static void	test_status(t_test_data *test_data, int fd)
{
	int		status;

	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			test_data->test_passed++;
		print_test_status(WEXITSTATUS(status));
		log_test_status(WEXITSTATUS(status), fd);
	}
	else if (WIFSIGNALED(status))
	{
		test_data->test_failed_signal++;
		print_test_status(WTERMSIG(status));
		log_test_status(WTERMSIG(status), fd);
	}
}

void	launch_tests(t_unit_test *testlist, char *f_name, int fd)
{
	t_test_data	test_data;

	test_data.test_count = 0;
	test_data.test_passed = 0;
	test_data.test_failed_signal = 0;
	while (testlist)
	{
		print_test(testlist, &test_data, f_name);
		log_test(testlist, &test_data, f_name, fd);
		test_data.pid = fork_test(testlist);
		if (test_data.pid == -1)
			break ;
		else
			test_status(&test_data, fd);
		testlist = testlist->next;
	}
	remove("tmp.txt");
	print_result(test_data.test_count, test_data.test_passed);
	log_result(test_data, fd);
	ft_lstclear(&testlist, NULL);
}
