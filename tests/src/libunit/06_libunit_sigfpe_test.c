/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_libunit_sigfpe_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 13:52:06 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	libunit_sigfpe_test(void)
{
	int	i;
	int	zero;

	zero = 0;
	i = 10;
	i = i / zero;
	return (0);
}
