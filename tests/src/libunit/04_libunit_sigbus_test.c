/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_libunit_sigbus_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 14:22:12 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"

int	libunit_sigbus_test(void)
{
	ft_strlcat("foo", "NULL", 42);
	return (0);
}
