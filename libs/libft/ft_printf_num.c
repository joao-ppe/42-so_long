/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:05:20 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/07/06 18:46:37 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_puthex(unsigned long nb, const char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_puthex((nb / 16), c);
		count += ft_puthex((nb % 16), c);
	}
	else
		count += write(1, &base[nb], 1);
	return (count);
}

int	ft_putpointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_puthex(nb, 'x');
	return (count);
}

static int	ft_count_digits(unsigned int n)
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

int	ft_utoa(unsigned int n)
{
	size_t	len;
	char	*numbers;
	int		count;

	count = 0;
	len = ft_count_digits(n);
	numbers = malloc((len + 1) * sizeof(char));
	if (!numbers)
		return (0);
	numbers[len] = '\0';
	if (n == 0)
		numbers[0] = '0';
	while (n != 0)
	{
		len--;
		numbers[len] = (n % 10) + '0';
		n = n / 10;
	}
	count += ft_putstr(numbers);
	free(numbers);
	return (count);
}
