/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_libunit_sigpipe_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 13:29:38 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

static void myHandler(int signo);

int	libunit_sigpipe_test(void)
{
	exit(SIGPIPE);
}
