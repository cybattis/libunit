/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:34:51 by cybattis          #+#    #+#             */
/*   Updated: 2022/01/16 22:38:46 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_all(char **strs, size_t i)
{
	while (i)
		free(strs[i--]);
	free(strs[i]);
	free(strs);
	return (NULL);
}
