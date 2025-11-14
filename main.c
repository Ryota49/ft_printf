/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:23:04 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/10 10:26:55 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str2;

	str = "salut";
	str2 = "bonjour";
	ft_printf("1er: %p\n2eme:%p\n", str, str2);
	printf("3eme: %p\n4eme:%p\n", str, str2);
}
