/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:13:39 by laufarin          #+#    #+#             */
/*   Updated: 2024/05/29 15:05:06 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*is_src;
	char			*is_dst;
	unsigned int	i;

	is_src = (char *) src;
	is_dst = (char *) dst;
	if (is_src == NULL && is_dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		is_dst[i] = is_src[i];
		i++;
	}
	return (dst);
}
