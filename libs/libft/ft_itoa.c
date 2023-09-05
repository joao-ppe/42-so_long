/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:40:28 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/05/04 15:08:47 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		signal;
	char	*numbers;

	len = ft_count_digits(n);
	signal = 1;
	numbers = malloc((len + 1) * sizeof(char));
	if (!numbers)
		return (NULL);
	numbers[len] = '\0';
	if (n < 0)
	{
		signal = -1;
		numbers[0] = '-';
	}
	else if (n == 0)
		numbers[0] = '0';
	while (n != 0)
	{
		len--;
		numbers[len] = (n % 10 * signal) + '0';
		n = n / 10;
	}
	return (numbers);
}
