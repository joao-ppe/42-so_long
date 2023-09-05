/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:43:45 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/04/15 15:43:45 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*pnstr;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	pnstr = malloc(len * (sizeof(char)));
	if (!pnstr)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		pnstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		pnstr[j++] = s2[i++];
	pnstr[j] = '\0';
	return (pnstr);
}
