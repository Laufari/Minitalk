/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:03 by laufarin          #+#    #+#             */
/*   Updated: 2024/05/30 16:36:10 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf/ft_printf.h"

static void	fill_buffer(char **buffer, int *buf_index, int *buf_size, char c);
static void	write_buffer(char **buffer, int *buf_index, int *buf_size );
static void	set_buffer(char **buffer, int *buf_size );

void	handle_signal(int sig)
{
	static int	c = 0;
	static int	bit_count = 0;
	static char	*buffer = NULL;
	static int	buff_index = 0;
	static int	buffer_size = 0;

	if (buffer == NULL)
		set_buffer(&buffer, &buffer_size);
	if (sig == SIGUSR2)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			write_buffer(&buffer, &buff_index, &buffer_size);
		else
			fill_buffer(&buffer, &buff_index, &buffer_size, c);
		c = 0;
		bit_count = 0;
	}
}

static void	set_buffer(char **buffer, int *buf_size)
{
	*buf_size = 1024;
	*buffer = (char *)malloc(*buf_size);
	if (!*buffer)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
}

static void	write_buffer(char **buffer, int *buf_index, int *buf_size)
{
	*(*buffer + *buf_index) = '\0';
	write(1, *buffer, *buf_index);
	write(1, "\n", 1);
	free(*buffer);
	*buffer = NULL;
	*buf_index = 0;
	*buf_size = 0;
}

static void	fill_buffer(char **buffer, int *buf_index, int *buf_size, char c)
{
	static char	*tmp;

	*(*buffer + *buf_index) = c;
	*buf_index += 1;
	if (*buf_index >= *buf_size)
	{
		*buf_size *= 2;
		tmp = *buffer;
		*buffer = (char *)malloc(*buf_size * sizeof(char));
		if (buffer == NULL)
		{
			write(2, "Error: malloc failed\n", 22);
			exit(EXIT_FAILURE);
		}
		ft_memcpy(*buffer, tmp, *buf_size / 2);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
