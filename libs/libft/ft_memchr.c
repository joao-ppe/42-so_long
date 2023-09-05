/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:11:17 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:09:31 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*newstr;

	newstr = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (newstr[i] == (unsigned char)c)
			return (newstr + i);
		i++;
		n--;
	}
	return (NULL);
}
