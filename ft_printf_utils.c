/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:48:36 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/14 12:04:20 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	(*ret)++;
}

void	ft_address_p(unsigned long long p, int *ret)
{
	char			*base;
	unsigned int	len_base;

	len_base = 16;
	base = "0123456789abcdef";
	if (p >= len_base)
	{
		ft_address_p(p / len_base, ret);
		ft_address_p(p % len_base, ret);
	}
	else
		ft_putchar(base[p], ret);
}

void	ft_putstr(char *str, int *ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		(*ret)++;
		i++;
	}
}

void	ft_putnbr(int nb, int *ret)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', ret);
		ft_putchar('2', ret);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', ret);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, ret);
		ft_putnbr(nb % 10, ret);
	}
	else
		ft_putchar(nb + '0', ret);
}

void	ft_putnbr_unsigned(unsigned int nb_unsigned, int *ret)
{
	if (nb_unsigned > 9)
	{
		ft_putnbr_unsigned(nb_unsigned / 10, ret);
		ft_putnbr_unsigned(nb_unsigned % 10, ret);
	}
	else
		ft_putchar(nb_unsigned + '0', ret);
}
