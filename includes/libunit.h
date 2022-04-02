

#ifndef LIBUNIT_H
# define LIBUNIT_H

#include "libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define TIMEOUT 5

typedef struct s_unit_test
{
	char	*test_name;
	int		(*f)(void);
	void	*next;
}	t_unit_test;

typedef struct s_test_data
{
	int		test_count;
	int		test_passed;
	pid_t	pid;
}	t_test_data;

void	launch_tests(t_unit_test *testlist);
void	print_test(t_unit_test *testlist, int *test_count);
void	print_test_status(t_unit_test *tlist, int t_count, int *t_passed, int status)
void	print_result(int test_count, int test_passed);

#endif
