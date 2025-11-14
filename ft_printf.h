/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:23:52 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/14 11:56:31 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	print_number_hexa_upper(unsigned int p, int *ret);
void	print_number_hexa_lower(unsigned int p, int *ret);
void	ft_putnbr_unsigned(unsigned int nb_unsigned, int *ret);
void	ft_putnbr(int nb, int *ret);
void	ft_putchar(char c, int *ret);
void	ft_address_p(unsigned long long p, int *ret);
void	ft_putstr(char *str, int *ret);
int		ft_printf(const char *str, ...);

#endif
