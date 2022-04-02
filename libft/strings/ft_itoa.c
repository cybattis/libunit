/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:52:13 by cybattis          #+#    #+#             */
/*   Updated: 2021/11/13 15:42:50 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbrlen(long nb);
static int	get_nbr(char *s, long n, int i);

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = get_nbrlen(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	get_nbr(s, n, i);
	if (n < 0)
		s[len - 1] = '-';
	s[len] = 0;
	ft_strnrev(s, ft_strlen(s) - 1);
	return (s);
}

static int	get_nbr(char *s, long nb, int i)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		get_nbr(s, nb / 10, i + 1);
	s[i] = nb % 10 + '0';
	return (0);
}

static int	get_nbrlen(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
