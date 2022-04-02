

#ifndef LIBUNIT_H
# define LIBUNIT_H

#include "libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_unit_test
{
	char *test_name;
	int (*f)(void);
	void *next;
}	t_unit_test;

void	launch_tests(t_unit_test *testlist);

#endif
