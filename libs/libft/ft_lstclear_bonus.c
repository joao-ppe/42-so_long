/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:46:44 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/03 13:58:52 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		next_node = aux->next;
		del(aux->content);
		free(aux);
		aux = next_node;
	}
	*lst = NULL;
}
