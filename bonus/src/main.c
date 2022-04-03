/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 16:54:35 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libunit.h"
#include "../includes/test_suite.h"

int	main(void)
{
	int	fd;

	fd = create_log_file();
	print_color_launcher(fd);
	ft_putstr_fd_launcher(fd);
	timeout_launcher(fd);
	signal_launcher(fd);
	close(fd);
	return (0);
}
