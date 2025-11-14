/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:01:21 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/10 10:22:55 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_address_p(unsigned long p)
{
	char			*base;
	unsigned int	len_base;

	len_base = 16;
	base = "0123456789abcdef";
	if (p >= len_base)
	{
		ft_address_p(p / len_base);
		ft_address_p(p % len_base);
	}
	else
		ft_putchar(base[p]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	check_after2(char c, va_list test)
{
	void	*p;

	if (c == 'p')
	{
		p = va_arg(test, void *);
		if (p == 0)
		{
			ft_putstr("(nil)");
			return (0);
		}
		ft_putstr("0x");
		ft_address_p((unsigned long)p);
	}
	return (0);
}

int	check_after(char c, va_list test)
{
	char	stock;
	char	*str;

	if (c == 'c')
	{
		stock = va_arg(test, int);
		write(1, &stock, 1);
	}
	else if (c == 's')
	{
		str = va_arg(test, char *);
		if (!str)
		{
			ft_putstr("(null)");
			return (0);
		}
		ft_putstr(str);
	}
	else if (c == '%')
		ft_putchar(1, '%', 1);
	else
		check_after2(c, test);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	test;
	int		i;

	i = 0;
	va_start(test, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_after(str[i], test);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}
