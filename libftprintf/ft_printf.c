/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:37 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:38 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_types(const char *s, int *i, int str_len, va_list argptr)
{
	if (s[*i + 1] == '%')
		str_len += ft_printf_char(s[*i]);
	else if (s[*i + 1] == 'i' || s[*i + 1] == 'd')
		str_len += ft_printf_int(va_arg(argptr, int));
	else if (s[*i + 1] == 'c')
		str_len += ft_printf_char(va_arg(argptr, int));
	else if (s[*i + 1] == 's')
		str_len += ft_printf_str(va_arg(argptr, char *));
	else if (s[*i + 1] == 'u')
		str_len += ft_printf_unint(va_arg(argptr, int));
	else if (s[*i + 1] == 'x' || s[*i + 1] == 'X')
		str_len += ft_printf_hexa(va_arg(argptr, unsigned int), s[*i + 1]);
	else if (s[*i + 1] == 'p')
		str_len += ft_printf_void(va_arg(argptr, size_t), s[*i + 1]);
	else
	{
		(*i)++;
		return (str_len);
	}
	(*i) += 2;
	return (str_len);
}

static int	print_list(va_list argptr, const char *s)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			str_len += ft_printf_char(s[i]);
			i++;
		}
		if (s[i] == '%')
			str_len = print_types(s, &i, str_len, argptr);
	}
	return (str_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		str_len;

	va_start(argptr, s);
	str_len = print_list(argptr, s);
	va_end(argptr);
	return (str_len);
}
