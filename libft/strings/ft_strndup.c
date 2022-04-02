/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:24:33 by cbattist          #+#    #+#             */
/*   Updated: 2021/11/13 15:58:31 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (src[i] && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
