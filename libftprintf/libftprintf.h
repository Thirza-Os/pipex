/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:18:42 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 11:18:43 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int				ft_printf(const char *s, ...);
int				ft_printf_int(int n);
int				ft_printf_str(char *str);
int				ft_printf_unint(unsigned int n);
int				ft_printf_char(char c);
int				ft_printf_hexa(size_t n, char c);
unsigned long	ft_strlen(const char *s);
int				ft_printf_address(unsigned long long n);
int				ft_printf_void(size_t pntr, char c);
#endif