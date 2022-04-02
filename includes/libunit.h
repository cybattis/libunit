

#ifndef LIBUNIT_H
#define LIBUNIT_H

typedef struct s_unit_suite
{
	size_t	test_count;
	size_t	test_fail;
	size_t	test_pass;
}	t_unit_suite;

typedef struct s_unit_test
{
	char *test_name;
	int (*f)(void);
	void *next;
}	t_unit_test;

#endif //LIBUNIT_H
