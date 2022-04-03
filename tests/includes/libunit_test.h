//
// Created by stb47 on 03/04/2022.
//

#ifndef LIBUNIT_TEST_H
#define LIBUNIT_TEST_H

int	libunit_ok_test(void);
int	libunit_ko_test(void);
int	libunit_sigsegv_test(void);
int	libunit_sigbus_test(void);
int	libunit_sigabort_test(void);
int	libunit_sigfpe_test(void);
int	libunit_sigpipe_test(void);
int	libunit_sigill_test(void);
int	libunit_timeout_test(void);

#endif
