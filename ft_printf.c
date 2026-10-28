/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:46:52 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/28 16:05:19 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatcher(va_list *args, char c)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar_pf(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr_pf(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunbr_pf(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex_pf(va_arg(*args, unsigned int), LOWER_HEX));
	if (c == 'X')
		return (ft_puthex_pf(va_arg(*args, unsigned int), UPPER_HEX));
	return (0);
}

static int	ft_handle(va_list *args, const char **str)
{
	if (**str != '%')
		return (write(1, *str, 1));
	(*str)++;
	if (!**str)
		return (-1);
	return (ft_dispatcher(args, **str));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		ret;

	counter = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		ret = ft_handle(&args, &str);
		if (ret < 0)
		{
			counter = -1;
			break ;
		}
		counter += ret;
		str++;
	}
	va_end(args);
	return (counter);
}
