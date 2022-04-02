

#ifndef LIBUNIT_H
# define LIBUNIT_H

#include "libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define TIMEOUT 5

typedef struct s_unit_test
{
	char *test_name;
	int (*f)(void);
	void *next;
}	t_unit_test;

void		load_test(t_unit_test **test_list, char *test_name, int (*f)(void));
void		launch_tests(t_unit_test *testlist);

t_unit_test	*ft_lstnew(char *test_name, int (*f)(void));
void		ft_lstadd_back(t_unit_test **alst, t_unit_test *new);
void		ft_lstdelone(t_unit_test *lst, void (*del)(void*));
void		ft_lstclear(t_unit_test **lst, void (*del)(void*));
int			ft_lstsize(t_unit_test *lst);

#endif
