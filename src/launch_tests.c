#include "../includes/libunit.h"
#include "../libft/libft.h"

static void	print_test(t_unit_test *testlist, int test_count, int *test_passed, int status);
static void	print_result(int test_count, int test_passed);

void	launch_tests(t_unit_test *testlist)
{
	int		test_count;
	int		test_passed;
	pid_t	pid;

	test_count = 0;
	test_passed = 0;
	while (testlist)
	{
		test_count++;
		pid = fork();
		if (pid == 0)
		{
			testlist->f();
			exit(0);
		}
		else
		{
			wait(&pid);
			if (WEXITSTATUS(pid) == 0)
				print_test(testlist, test_count, &test_passed, 0);
			else if (WSTOPSIG(pid) == SIGBUS)
				print_test(testlist, test_count, &test_passed, SIGBUS);
			else if (WSTOPSIG(pid) == SIGSEGV)
				print_test(testlist, test_count, &test_passed, SIGSEGV);
			else
				print_test(testlist, test_count, &test_passed, -1);
		}
		testlist = testlist->next;
	}
	print_result(test_count, test_passed);
}

static void	print_test(t_unit_test *testlist, int test_count, int *test_passed, int status)
{
	ft_putstr_fd("Test ", 1);
	ft_putnbr_fd(test_count, 1);
	ft_putstr_fd(":", 1);
	ft_putstr_fd(testlist->test_name, 1);
	ft_putstr_fd(":", 1);
	if (status == 0)
	{
		(*test_passed)++;
		ft_putstr_fd("OK\n", 1);
	}
	else if (status == SIGSEGV)
		ft_putstr_fd("SIGSEGV\n", 1);
	else if (status == SIGBUS)
		ft_putstr_fd("SIGBUS\n", 1);
	else
		ft_putstr_fd("Unknown error\n", 1);
}

static void	print_result(int test_count, int test_passed)
{
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(test_passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(test_count, 1);
	ft_putstr_fd(" tests checked\n", 1);
}
