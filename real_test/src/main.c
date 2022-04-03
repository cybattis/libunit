/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/03 15:54:40 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libunit.h"
#include "../includes/test_suite.h"

int	main(void)
{
	int	fd;

	fd = create_log_file();
	ft_strlen_launcher(fd);
	ft_atoi_launcher(fd);
	ft_strlcat_launcher(fd);
	ft_putstr_fd_launcher(fd);
	close(fd);
	return (0);
}
