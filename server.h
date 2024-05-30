/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:11:21 by laufarin          #+#    #+#             */
/*   Updated: 2024/05/30 14:12:49 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void		handle_signal(int sig);
void		*ft_memcpy(void *dst, const void *src, size_t n);
static void	set_buffer(char **buffer, int *buf_size );
static void	write_buffer(char **buffer, int *buf_index, int *buf_size );
static void	fill_buffer(char **buffer, int *buf_index, int *buf_size, char c);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif 
