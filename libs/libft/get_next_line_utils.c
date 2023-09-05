/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:19:31 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/07/04 17:42:57 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strclen(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	len = (gnl_strclen(s1, '\0') + gnl_strclen(s2, '\0'));
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[i] != '\0')
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	if (s1)
		free(s1);
	return (newstr);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strncpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = gnl_strclen(src, '\n');
	i = 0;
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (len_src);
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

char	*gnl_strndup(char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*pnewstr;

	i = 0;
	len = gnl_strclen(s1, '\0');
	pnewstr = malloc(sizeof(char) * (len + 1));
	if (!pnewstr)
		return (NULL);
	while (i < n)
	{
		pnewstr[i] = s1[i];
		i++;
	}
	pnewstr[i] = '\0';
	return (pnewstr);
}
