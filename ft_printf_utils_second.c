/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:45:15 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/14 12:02:05 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number_hexa_upper(unsigned int p, int *ret)
{
	char			*base;
	unsigned int	len_base;

	len_base = 16;
	base = "0123456789ABCDEF";
	if (p >= len_base)
	{
		print_number_hexa_upper(p / len_base, ret);
		print_number_hexa_upper(p % len_base, ret);
	}
	else
		ft_putchar(base[p], ret);
}

void	print_number_hexa_lower(unsigned int p, int *ret)
{
	char			*base;
	unsigned int	len_base;

	len_base = 16;
	base = "0123456789abcdef";
	if (p >= len_base)
	{
		print_number_hexa_lower(p / len_base, ret);
		print_number_hexa_lower(p % len_base, ret);
	}
	else
		ft_putchar(base[p], ret);
}
