/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 10:07:39 by pniezen       #+#    #+#                 */
/*   Updated: 2021/12/16 13:01:40 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	conversion(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_putaddress(va_arg(*ap, unsigned long)));
	if (c == 'd')
		return (ft_putnbr(va_arg(*ap, int), 10, 'd'));
	if (c == 'i')
		return (ft_putnbr(va_arg(*ap, int), 10, 'i'));
	if (c == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int), 10, 'u'));
	if (c == 'x')
		return (ft_putnbr(va_arg(*ap, unsigned int), 16, 'x'));
	if (c == 'X')
		return (ft_putnbr(va_arg(*ap, unsigned int), 16, 'X'));
	if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (0);
			count += conversion(format[i + 1], &ap);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
