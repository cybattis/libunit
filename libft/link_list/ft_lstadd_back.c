/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by cybattis          #+#    #+#             */
/*   Updated: 2022/04/02 15:20:45 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ft_lstadd_back(t_unit_test **alst, t_unit_test *new)
{
	if (*alst == NULL)
		*alst = new;
	else
	{
		while ((*alst)->next)
			alst = (t_unit_test **)&(*alst)->next;
		(*alst)->next = new;
	}
}
