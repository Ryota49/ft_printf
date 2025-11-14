/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:01:21 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/14 12:05:08 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_after3(char c, va_list args, int *ret)
{
	unsigned int	nbr_hexa;
	unsigned int	nb_unsigned;

	if (c == 'u')
	{
		nb_unsigned = va_arg(args, unsigned int);
		ft_putnbr_unsigned(nb_unsigned, ret);
	}
	else if (c == 'x')
	{
		nbr_hexa = va_arg(args, unsigned int);
		print_number_hexa_lower(nbr_hexa, ret);
	}
	else if (c == 'X')
	{
		nbr_hexa = va_arg(args, unsigned int);
		print_number_hexa_upper(nbr_hexa, ret);
	}
}

void	check_after2(char c, va_list args, int *ret)
{
	void	*p;
	int		nb;

	if (c == 'p')
	{
		p = va_arg(args, void *);
		if (p == 0)
		{
			ft_putstr("(nil)", ret);
			return ;
		}
		ft_putstr("0x", ret);
		ft_address_p((unsigned long long)p, ret);
	}
	else if (c == 'd' || c == 'i')
	{
		nb = va_arg(args, int);
		ft_putnbr(nb, ret);
	}
	else
		check_after3(c, args, ret);
}

void	check_after(char c, va_list args, int *ret)
{
	char	stock;
	char	*str;

	if (c == 'c')
	{
		stock = va_arg(args, int);
		write(1, &stock, 1);
		(*ret)++;
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr("(null)", ret);
			return ;
		}
		ft_putstr(str, ret);
	}
	else if (c == '%')
		ft_putchar('%', ret);
	else
		check_after2(c, args, ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			check_after(str[i], args, &ret);
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}
