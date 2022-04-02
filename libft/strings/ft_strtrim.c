/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:33:22 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/10 15:07:42 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	while (end && ft_strchr(set, s1[end - 1]) != 0)
		end--;
	if (end > start)
		end = (end - start) + 1;
	else
		end = 1;
	str = malloc(sizeof(char) * end);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end);
	return (str);
}
