/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:54:23 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:12:15 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((n - 1) > 0 && (s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
		n--;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
