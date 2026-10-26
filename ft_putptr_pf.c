/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:58:13 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/26 16:39:14 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(void *ptr)
{
	unsigned long	addr;
	int					len;

	addr = (unsigned long)ptr;
	len = ft_putstr_pf("0x");
	len += ft_puthex_pf(addr, 0);
	return (len);
}
