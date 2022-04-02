/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:09:34 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/12 17:13:00 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*pos;

	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		pos = (char *)&s[i];
	return (pos);
}
