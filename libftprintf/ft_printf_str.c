/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:29 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:30 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_str(char *str)
{
	int	len;

	if (str == NULL)
		str = ("(null)");
	len = ft_strlen(str);
	while (*str)
	{
		ft_printf_char(*str);
		str++;
	}
	return (len);
}
