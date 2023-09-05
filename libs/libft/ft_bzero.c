/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:32 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/07/04 18:21:50 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*str, size_t	n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) str;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
