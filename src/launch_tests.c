#include "../includes/libunit.h"
#include "../libft/libft.h"

static void	print_test(t_unit_test *testlist, int test_count, int *test_passed, int status);
static void	print_result(int test_count, int test_passed);

void	timeout_handler(int sig)
{
	(void)sig;
	exit(-1);
}

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
			signal(SIGALRM, timeout_handler);
			if (TIMEOUT > 0)
				alarm(TIMEOUT);
			testlist->f();
			exit(0);
		}
		else
		{
			wait(&pid);
			if (WEXITSTATUS(pid) == 0)
				print_test(testlist, test_count, &test_passed, 0);
			else if (WEXITSTATUS(pid) == -1)
				print_test(testlist, test_count, &test_passed, -1);
			else if (WIFSTOPPED(pid))
				print_test(testlist, test_count, &test_passed, WSTOPSIG(pid));
			else
				print_test(testlist, test_count, &test_passed, -2);
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
		ft_putstr_fd("\033[32mOK\n\033[0m", 1);
	}
	else if (status == SIGSEGV)
		ft_putstr_fd("\033[33mSIGSEGV\n\033[0m", 1);
	else if (status == SIGBUS)
		ft_putstr_fd("\033[33mSIGBUS\n\033[0m", 1);
	else if (status == SIGABRT)
		ft_putstr_fd("\033[33mSIGABRT\n\033[0m", 1);
	else if (status == SIGFPE)
		ft_putstr_fd("\033[33mSIGFPE\n\033[0m", 1);
	else if (status == SIGPIPE)
		ft_putstr_fd("\033[33mSIGPIPE\n\033[0m", 1);
	else if (status == SIGILL)
		ft_putstr_fd("\033[33mSIGILL\n\033[0m", 1);
	else if (status == -1)
		ft_putstr_fd("\033[1;30mTIMEOUT\n\033[0m", 1);
	else
		ft_putstr_fd("\033[31mKO\n\033[0m", 1);
}

static void	print_result(int test_count, int test_passed)
{
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(test_passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(test_count, 1);
	ft_putstr_fd(" tests checked\n", 1);
}
