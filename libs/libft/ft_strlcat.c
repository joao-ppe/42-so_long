/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:25:42 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:11:59 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	j;
	size_t	i;

	srclen = ft_strlen(src);
	if (dest)
		destlen = ft_strlen(dest);
	else
		destlen = 0;
	j = destlen;
	i = 0;
	if (size == 0 || size < destlen)
		return (srclen + size);
	while (src[i] != '\0' && j < (size - 1))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (destlen + srclen);
}
