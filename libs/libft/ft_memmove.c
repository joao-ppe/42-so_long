/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:06 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:09:39 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	if (!src && !dest)
		return (NULL);
	pdest = dest;
	psrc = src;
	if (src < dest)
	{
		while (n != 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else if (src > dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
