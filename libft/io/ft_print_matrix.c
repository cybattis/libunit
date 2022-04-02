/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:17:13 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/16 21:36:44 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(int fd, t_vec3 **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_dprintf(fd, "[%d, %d, %d]\n",
				(int)matrix[i][j].x, (int)matrix[i][j].y, (int)matrix[i][j].z);
			j++;
		}
		i++;
	}
}
