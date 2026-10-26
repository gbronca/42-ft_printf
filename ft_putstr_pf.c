/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:13:09 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/26 21:33:59 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_pf(char *s)
{
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, s, ft_strlen(s)));
}
