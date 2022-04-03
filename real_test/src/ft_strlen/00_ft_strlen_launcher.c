/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strlen_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
<<<<<<< HEAD:tests/src/ft_strlen/00_ft_strlen_launcher.c
/*   Updated: 2022/04/03 11:26:08 by ctaleb           ###   ########lyon.fr   */
=======
/*   Updated: 2022/04/03 11:24:28 by cybattis         ###   ########.fr       */
>>>>>>> 4e8ed3c0e97beefbd139211796ec8fd64c582ac0:real_test/src/ft_strlen/00_ft_strlen_launcher.c
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_strlen_test.h"

int	ft_strlen_launcher(void)
{
	t_unit_test	*test_list = NULL;

	load_test(&test_list, "Basic test", &ft_strlen_basic_test);
	load_test(&test_list, "NULL test", &ft_strlen_null_test);
	load_test(&test_list, "Timeout test", &ft_strlen_timeout_test);
	launch_tests(test_list, "[FT_STRLEN]");
	return (0);
}
