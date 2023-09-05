/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:26 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/07/04 17:39:28 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (!spec)
		return (0);
	else if (spec == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_putpointer(va_arg(ap, unsigned long));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		count += ft_utoa(va_arg(ap, unsigned int));
	else if (spec == 'x')
		count += ft_puthex(va_arg(ap, unsigned int), spec);
	else if (spec == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), spec);
	else if (spec == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (0);
	while (*format != 0)
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
