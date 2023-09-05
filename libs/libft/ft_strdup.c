/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:08:30 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:11:49 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*pnewstr;

	i = 0;
	len = ft_strlen(s) + 1;
	pnewstr = malloc(sizeof(char) * len);
	if (!pnewstr)
		return (NULL);
	while (s[i])
	{
		pnewstr[i] = s[i];
		i++;
	}
	pnewstr[i] = '\0';
	return (pnewstr);
}
