/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:52:29 by ctaleb            #+#    #+#             */
/*   Updated: 2022/04/03 10:46:24 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include "../libft/libft.h"

static pid_t	fork_test(t_unit_test *testlist)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		if (TIMEOUT > 0)
			alarm(TIMEOUT);
		testlist->f();
		exit(0);
	}
	return (pid);
}

static void	test_status(t_test_data *test_data)
{
	int		status;

	wait(&status);
	if (status == 0)
		test_data->test_passed++;
	print_test_status(status);
}

void	launch_tests(t_unit_test *testlist, char *f_name)
{
	t_test_data	test_data;

	test_data.test_count = 0;
	test_data.test_passed = 0;
	while (testlist)
	{
		print_test(testlist, &test_data, f_name);
		test_data.pid = fork_test(testlist);
		if (test_data.pid == -1)
			break ;
		else
			test_status(&test_data);
		testlist = testlist->next;
	}
	print_result(test_data.test_count, test_data.test_passed);
	ft_lstclear(&testlist, free);
}
