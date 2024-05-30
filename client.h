/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:15:53 by laufarin          #+#    #+#             */
/*   Updated: 2024/05/30 12:01:27 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

static int	is_space(char c);
int			ft_atoi(const char *str);
void		char_to_bit(int pid, char c);
void		str_to_bit(int pid, char *str);

#endif
