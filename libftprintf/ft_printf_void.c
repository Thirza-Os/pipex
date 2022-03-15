/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_void.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:34 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:35 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_void(size_t pntr, char c)
{
	int					len;

	write(1, "0x", 2);
	len = ft_printf_hexa(pntr, c);
	return (len + 2);
}
