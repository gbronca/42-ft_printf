/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:09:07 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/26 16:32:33 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putunbr_pf(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putunbr_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}

int	ft_putnbr_pf(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_putchar_pf('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr_pf(nbr / 10);
		count += ft_putchar_pf((nbr % 10) + '0');
	}
	else
	{
		count += ft_putchar_pf(nbr + '0');
	}
	return (count);
}

int	ft_puthex_pf(unsigned long n, int upper)
{
	int		count;
	char	*base;

	count = 0;
	if (!upper)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		count += ft_puthex_pf(n / 16, upper);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}