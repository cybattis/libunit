/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:17:21 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/10 15:02:13 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_size;
	unsigned int	src_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (size + src_size);
	if (*src)
	{
		dst += dst_size;
		size -= dst_size;
		while (*src && (size - 1) > 0)
		{
			*dst++ = *src++;
			size--;
		}
		*dst = 0;
	}
	return (dst_size + src_size);
}
