/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:09:07 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/28 15:27:31 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** **
** 						ft_putunbr_pf(unsigned int n)						  **
**	ret checks for errors in writing characters and returns -1 if an error	  **
**	occurs																	  **
**	count keeps track of the number of characters printed successfully	  	  **
**																			  **
** ************************************************************************** */

int	ft_putunbr_pf(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n > 9)
	{
		count = ft_putunbr_pf(n / 10);
		if (count < 0)
			return (-1);
	}
	ret = ft_putchar_pf((n % 10) + '0');
	if (ret < 0)
		return (-1);
	return (count + ret);
}

/* ************************************************************************** **
** 						ft_putnbr_pf(int n)									  **
** ft_putnbr_pf uses ft_putunbr_pf to print digits, so the number-printing	  **
** logic exists only once.												  	  **
** The - sign is the only part it prints itself.							  **
** ************************************************************************** */

int	ft_putnbr_pf(int n)
{
	long	nbr;
	int		count;
	int		ret;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count = ft_putchar_pf('-');
		if (count < 0)
			return (-1);
		nbr = -nbr;
	}
	ret = ft_putunbr_pf((unsigned int)nbr);
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_puthex_pf(unsigned long n, char *base)
{
	int		count;

	count = 0;
	if (n > 15)
		count += ft_puthex_pf(n / 16, base);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}

int	ft_putptr_pf(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	len = ft_putstr_pf("0x");
	if (len < 0)
		return (-1);
	ret = ft_puthex_pf((unsigned long)ptr, LOWER_HEX);
	if (ret < 0)
		return (-1);
	return (len + ret);
}
