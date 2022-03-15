/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hexa.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:24 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:25 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_i(size_t n)
{
	int					i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	check_char(char c)
{
	char	hex;

	if (c == 'X')
		hex = '7';
	if (c == 'x' || c == 'p')
		hex = 'W';
	return (hex);
}

static char	*fill_str(size_t num, char *str, int i, char c)
{
	unsigned long long	temp;
	char				hex;

	hex = check_char(c);
	str[i] = '\0';
	i--;
	if (num == 0)
		str[i] = '0';
	while (num != 0 && i >= 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + '0';
		}
		else
		{
			str[i] = temp + hex;
		}
		num = num / 16;
		i--;
	}
	return (str);
}

int	ft_printf_hexa(size_t n, char c)
{
	int					i;
	char				*str;

	i = count_i(n);
	str = malloc(sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	str = fill_str(n, str, i, c);
	ft_printf_str(str);
	i = (ft_strlen(str));
	free(str);
	return (i);
}
