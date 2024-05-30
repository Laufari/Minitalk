/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:15:00 by laufarin          #+#    #+#             */
/*   Updated: 2023/10/23 17:19:41 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define BASE_MAYUS "0123456789ABCDEF"
# define BASE_MIN "0123456789abcdef"

int	ft_printf(const char *s, ...);
int	ft_printf_strings(char *s);
int	ft_printf_prcnt(char c);
int	ft_printf_numbers(int num);
int	ft_unsigned(unsigned int n);
int	ft_printf_hexa(unsigned int nb);
int	ft_printf_hexamin(unsigned int nb);
int	ft_printf_char(char c);
int	ft_printf_pointer(unsigned long nb);

#endif
