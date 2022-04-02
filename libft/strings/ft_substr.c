/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:30:09 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/10 15:09:00 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	size = ft_strlen(s);
	if (size > len)
		size = len;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
