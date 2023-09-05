/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:19:25 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 16:49:45 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char				*new;
	unsigned int		total;

	total = nmemb * size;
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, total);
	return ((void *)new);
}
/* 
int	main(void)
{
	char	*str;

	str = ft_calloc(5, sizeof(int));
	return (0);
} 
*/