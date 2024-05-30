/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/05/30 14:10:22 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	is_space(char c)
{
	while (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	resultado;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	resultado = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = resultado * 10 + (str[i] - '0');
		i++;
	}
	return (resultado * sign);
}

void	char_to_bit(int pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (c & (1 << bit_count))
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		bit_count++;
		usleep(75);
	}
}

void	str_to_bit(int pid, char *str)
{
	int	i;
	int	bit_count;

	i = 0;
	bit_count = 8;
	while (*str != '\0')
	{
		char_to_bit(pid, *str);
		str++;
	}
	char_to_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error los argumentos son incorrectos\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error pid incorrecto\n");
		return (1);
	}
	str_to_bit(pid, argv[2]);
	return (0);
}
