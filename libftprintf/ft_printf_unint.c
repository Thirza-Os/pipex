/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_unint.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:32 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:33 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

int	ft_printf_unint(unsigned int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num = num + UINT_MAX + 1;
	}
	if ((num / 10) > 0)
	{
		ft_printf_int(num / 10);
	}
	ft_printf_char(num % 10 + '0');
	return (ft_intlen(n));
}
