/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:47:35 by pniezen       #+#    #+#                 */
/*   Updated: 2021/12/16 13:08:58 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(long num, int base, char choice)
{
	char	*num_conv;
	int		count;

	count = 0;
	if (choice == 'X')
		num_conv = "0123456789ABCDEF";
	else
		num_conv = "0123456789abcdef";
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count += 1;
	}
	if (num / base != 0)
		count += ft_putnbr(num / base, base, choice);
	num = (num % base);
	write(1, &num_conv[num], 1);
	count += 1;
	return (count);
}

static int	ft_puthex(unsigned long num, char choice)
{
	char	*hexa;
	int		count;

	count = 0;
	if (choice == 'x')
		hexa = "0123456789abcdef";
	if (choice == 'X')
		hexa = "0123456789ABCDEF";
	if (num / 16 != 0)
		count += ft_puthex(num / 16, choice);
	num = (num % 16);
	write(1, &hexa[num], 1);
	count += 1;
	return (count);
}

int	ft_putaddress(unsigned long num)
{
	int	count;

	write(1, "0x", 2);
	count = 2;
	count += ft_puthex(num, 'x');
	return (count);
}
