/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:47:44 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/28 10:20:01 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

int	ft_printf(const char *str, ...);

int	ft_putchar_pf(char c);
int	ft_putnbr_pf(int n);
int	ft_putunbr_pf(unsigned int n);
int	ft_putstr_pf(char *s);
int	ft_puthex_pf(unsigned long n, char *base);
int	ft_putptr_pf(void *ptr);

#endif